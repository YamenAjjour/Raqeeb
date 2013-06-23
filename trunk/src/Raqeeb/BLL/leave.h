#ifndef LEAVE_H
#define LEAVE_H
#include <QDate>
#include <QString>
#include <QVector>
class Leave
{
private :
    int id ;
    QDate leaveDate;
    QDate requestDate;
    QDate endDate;
    int payType;
    QVector<int> employeeids;
public:
    Leave(int id , QDate ldate,QDate rdate,QDate enddate, int payType,QVector<int> employeeids);
    Leave();
    bool AddToStorage(QString &MessageError);
    QString static paidTypeMapper(int x);
    bool update();
    bool deleteMe();
    //setters
    void setId(int id );
    void setLeaveDate(QDate ldate);
    void setRequestDate(QDate rdate);
    void setPayType(int payType);
    void setEmployeeIds(QVector<int> &empids);
    void setEndDate( QDate edate);
    //getters
    int getId();
    QDate getLeaveDate();
    QDate getRequestDate();
    int getPayType();
    const QVector<int>& getEmployeeIds();
    QDate getEndDate();

};

#endif // LEAVE_H
