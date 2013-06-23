#include "userdal.h"
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include"../BLL/user.h"
QSqlQuery* UserDal::q = NULL;
QString UserDal::lastError = QString("");
UserDal::UserDal()
{
}

QSqlError UserDal::getLastError()
{
    if(q)
        return lastError;
    else
        return QString("");
}
bool UserDal::initQuery()
{
    QSqlDatabase db = QSqlDatabase::database("employee.dat");
    if(db.open())
    {
        if(!q)
            q= new QSqlQuery(db);
        else
            q->clear();
        return true;
    }
    qDebug()<<db.lastError().text();
    return false;
}

void UserDal::finalizeQuery()
{
    lastError = q->lastError().text();
    delete q;
    q=NULL;
}

bool UserDal::addUser(User* u,QString & messageError)
{
    bool result;
    if(initQuery())
    {
        q->prepare("insert into emp(firstname,lastname,email,phone,anotheremail,mobile,hourprice,machineid) values(  :fn, :ln, :email, :phone, :aemail ,:mobile,:hprice ,:mid);");
        q->bindValue(":mid",u->getMachineId());
        q->bindValue(":fn",u->getFirstName());
        q->bindValue(":ln",u->getLastName());
        q->bindValue(":email",u->getEmail());
        q->bindValue(":phone",u->getPhone());
        q->bindValue(":aemail",u->getAnotherEmail());
        q->bindValue(":mobile",u->getMobile());
        q->bindValue(":hprice",u->getHourPrice());
        result =q->exec();
        finalizeQuery();
        return result;
    }
    finalizeQuery();
    return false;
}

bool  UserDal::getAllUser(QList<User>& users)
{
    if(initQuery())
    {
        q->prepare("select empid,firstname,lastname,email,phone,anotheremail,mobile,hourprice,machineid from emp");
        q->exec();
        while(q->next())
        {
            User u;
            u.setId(q->value(0).toInt());
            u.setFirstName(q->value(1).toString());
            u.setLastName(q->value(2).toString());
            u.setEmail(q->value(3).toString());
            u.setPhone(q->value(4).toString());
            u.setAnotherEmail(q->value(5).toString());
            u.setMobile(q->value(6).toString());
            u.setHourPrice(q->value(7).toDouble());
            u.setMachineId(q->value(8).toInt());
            users.append(u);
        }
        finalizeQuery();
        return true;
    }
    finalizeQuery();
    return false;
}


 bool UserDal::getUserById(int id , User& u)
{
        if(initQuery())
    {
        q->prepare("select empid,firstname,lastname,email,phone,anotheremail,mobile,hourprice,machineid from emp where empid =:id");
        q->bindValue(":id",id);
        q->exec();
        if(q->next())
        {
            u.setId(q->value(0).toInt());
            u.setFirstName(q->value(1).toString());
            u.setLastName(q->value(2).toString());
            u.setEmail(q->value(3).toString());
            u.setPhone(q->value(4).toString());
            u.setAnotherEmail(q->value(5).toString());
            u.setMobile(q->value(6).toString());
            u.setHourPrice(q->value(7).toDouble());
            u.setMachineId(q->value(8).toInt());
            finalizeQuery();
            return true;
        }
        else
        {
            finalizeQuery();
            return false;
        }
    }
    return false;
}

 bool UserDal::getAllUserStartBy(QString &prefix,QVector<User>& users)
{
     if(initQuery())
    {
        q->prepare("select empid,name from emp where firstname like :prefix+'%'");
        q->bindValue(":prefix",prefix);
        q->exec();
        while(q->next())
        {
            User u;
            u.setId(q->value(0).toInt());
            u.setFirstName(q->value(1).toString());
            users.append(u);

        }
        finalizeQuery();
        return true;
    }
     finalizeQuery();
     return false;
 }

 bool UserDal::updateUser(User *u)
 {
     bool result;
     if(initQuery()&& u)
     {
         q->prepare("update emp set firstname = :fname , lastname =:lname , email=:email , phone=:phone , anotheremail=:aemail , mobile=:mobile, hourprice=:hourprice,machineid=:mid where empid=:id  ");
         q->bindValue(":fname",u->getFirstName());
         q->bindValue(":lname",u->getLastName());
         q->bindValue(":email",u->getEmail());
         q->bindValue(":phone",u->getPhone());
         q->bindValue(":aemail",u->getAnotherEmail());
         q->bindValue(":mobile",u->getMobile());
         q->bindValue(":hourprice",u->getHourPrice());
         q->bindValue(":mid",u->getMachineId());
         q->bindValue(":id",u->getId());
         result= q->exec();
         finalizeQuery();
         return result;
     }
     finalizeQuery();
     return false;
 }
