#ifndef LEAVE_H
#define LEAVE_H
#include <QDate>
#include <QString>

class Leave
{
private :
    int id ;
    QDate leaveDate;
    QDate requestDate;
    int payType;
    int employeeid;
public:
    Leave(int id , QDate ldate,QDate rdate, int payType,int employeeid);
    Leave();
    bool AddToStorage(QString &MessageError);
    QString static paidTypeMapper(int x);
    //setters
    void setId(int id );
    void setLeaveDate(QDate ldate);
    void setRequestDate(QDate rdate);
    void setPayType(int payType);
    void setEmployeeId(int empid);
    //getters
    int getId();
    QDate getLeaveDate();
    QDate getRequestDate();
    int getPayType();
    int getEmployeeId();

};

#endif // LEAVE_H
