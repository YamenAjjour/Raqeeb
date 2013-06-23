#ifndef USER_H
#define USER_H
#include <QString>
#include <QVector>
#include <QPair>
#include <QList>
#include "log.h"
#include <QList>
#include <QDate>
#include "leave.h"
class User
{
public:
    User();
    User(int id , QString firstName , QString lastName, QString email ,QString phone,QString anotherEmail,QString mobile , double hourPrice);

    void setId(int id){this->id=id;}
    void setHourPrice(double hourPrice){this->hourPrice=hourPrice;}
    void setFirstName(QString firstName){this->firstName=firstName;}
    void setLastName(QString lastName);
    void setEmail(QString Email);
    void setAnotherEmail(QString AnotherEmail);
    void setPhone(QString phone);
    void setMobile(QString mobile);
    void setMachineId(int id );

    int getId() const;
    double getHourPrice() const;
    QString getFirstName() const;
    QString getEmail() const;
    QString getLastName() const;
    QString getAnotherEmail() const;
    QString getPhone() const;
    QString getMobile() const;
    int getMachineId() const;

    QVector<User> getAllUserStartBy(QString prefix);
    bool getUserById(int id , User &u);
    bool operator ==(const User& other) const {return this->getMachineId()==other.getMachineId();}
    void addLog(Log &lg){logs.append(lg);}
    int calcHour();
    int calcHour(QDate startDate , QDate endDate , QList<Log> & daysForgToSigOff , QList<QPair<Log,Log> > &nightShift);
    bool addToStorage();
    bool update();
    bool getLeavesByDate(QDate edate , QDate sdate , QList<Leave*> &leaves);
    QVector<Log> logs;
    bool InitfromStorage();
private:
    int id;
    int machineid;
    double hourPrice;
    QString firstName;
    QString lastName;
    QString email;
    QString anotherEmail;
    QString phone;
    QString mobile;
};

#endif // USER_H
