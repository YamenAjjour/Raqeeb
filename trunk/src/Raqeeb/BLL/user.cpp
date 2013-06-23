#include "user.h"
#include <QPair>
#include <QDate>
#include "../DAL/userdal.h"
#include <QSqlError>
#include <QMessageBox>
#include "../DAL/leavedal.h"

int getIndOfTheLastLogOfDay(QVector<Log>& logs,QDate theday)
{
    int counter =0;
    for(int i=0;i!=logs.count();i++)
    {
        if((i+1)==logs.count())
            return -1;
        else
            if((logs[i].getDate().day()==theday.day())&&(logs[i+1].getDate().day()!=theday.day()))
                return i;
    }
    return -1;
}

int getNumOfLogOfDay(QVector<Log>& logs , QDate theday)
{
    int counter =0;
    foreach(Log lg,logs)
    {
        if(lg.getDate().day()==theday.day())
            counter++;
    }
    return counter;
}

int getIndOfLog(QVector<Log>& logs,QDate theday)
{
    for(int i =0;i<logs.count();i++)
    {
        if((logs[i].getDate().day()==theday.day())&&(logs[i].getDate().month()==theday.month())&&(logs[i].getDate().year()==theday.year()))
            return i;
        if((logs[i].getDate().day()>theday.day())&&(logs[i].getDate().month()==theday.month())&&(logs[i].getDate().year()==theday.year()))
            return i;
    }
    return -1;
}

User::User()
{
}

User::User(int machineid, QString firstName, QString lastName, QString email, QString phone, QString anotherEmail, QString mobile, double hourPrice)
{
    setMachineId(machineid);
    setHourPrice(hourPrice);
    setFirstName(firstName);
    setLastName(lastName);
    setEmail(email);
    setPhone(phone);
    setAnotherEmail(anotherEmail);
    setMobile(mobile);
    setHourPrice(hourPrice);
}

int User::calcHour(QDate startDate , QDate endDate , QList<Log> & daysForgToSigOff , QList<QPair<Log,Log> > &nightShift)
{
    QList<Leave*> leaves;
    getLeavesByDate(startDate,endDate,leaves);
    QDate  dayBefFirDay = startDate.addDays(-1);
    Log lg1(dayBefFirDay,0,0,QTime());
    int counter;
    int sum=0;
    Log lg(startDate,0,0,QTime());
    counter= getIndOfLog(logs,startDate);
    if(counter==-1)
        return 0;
    while(counter<logs.count()&&logs[counter].getDate()<endDate.addDays(1))
    {
        if((counter+1)>=logs.count())
            return sum/60+1;
        if(logs[counter].getDate().day()==logs[counter+1].getDate().day())
        {
            sum+=logs[counter+1].getMins()-logs[counter].getMins();
            counter+=2;
        }
        else if(logs[counter].getDate().addDays(1).day()==logs[counter+1].getDate().day())
        {
            if(logs[counter].getStatus()==0&&logs[counter+1].getStatus()==1)
            {
                QPair<Log,Log> pair;
                pair.first=logs[counter];
                pair.second=logs[counter+1];
                nightShift.append(pair);
                sum+=24*60-logs[counter].getMins();
                sum+=logs[counter+1].getMins();
                counter+=2;
            }
            else
            {
                daysForgToSigOff.append(logs[counter]);
                counter++;
            }
        }
        else
        {
            daysForgToSigOff.append(logs[counter]);
            counter++;
        }
    }
    return (sum/60)+1;

}

bool User::addToStorage()
{
   QString error;
   if(!UserDal::addUser(this,error))
       QMessageBox::warning(0,"database error",error,QMessageBox::Ok);
}

bool User::update()
{
    if(!UserDal::updateUser(this))
    {
        QMessageBox::warning(0,"database error" ,UserDal::getLastError().text());
    }
}

bool User::getLeavesByDate(QDate edate, QDate sdate, QList<Leave*> &leaves)
{
   leaves.clear();
   LeaveDal::getLeaveByDate(getMachineId(),sdate,edate,leaves);
}
// getters
double User::getHourPrice() const
{
    return hourPrice;
}

int User::getId() const
{
    return id;
}

QString User::getFirstName() const
{
    return firstName;
}

QString User::getLastName()const
{
    return lastName;
}

QString User::getEmail()const
{
    return email;
}

QString User::getAnotherEmail()const
{
    return anotherEmail;
}

QString User::getPhone()const
{
    return phone;
}

QString User::getMobile()const
{
    return mobile;
}

//setters

void User::setEmail(QString Email)
{
    this->email=Email;
}

void User::setAnotherEmail(QString AnotherEmail)
{
    this->anotherEmail=AnotherEmail;
}

void User::setLastName(QString lastName)
{
    this->lastName=lastName;
}

void User::setMobile(QString mobile)
{
    this->mobile=mobile;
}

void User::setPhone(QString phone)
{
    this->phone=phone;
}

void User::setMachineId(int id)
{
    this->machineid=id;
}

QVector<User> User::getAllUserStartBy(QString prefix)
{
    QVector<User> users;
    UserDal::getAllUserStartBy(prefix,users);
    return users;
}

bool User::getUserById(int id, User &u)
{
    return UserDal::getUserById(id,u);
}

bool User::InitfromStorage()
{
    if(UserDal::getUserById(id,*this))
        return true;
    else
    {
        return false;
    }
}

int User::getMachineId() const
{
    return machineid;
}
