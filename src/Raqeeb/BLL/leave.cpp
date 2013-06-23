#include "leave.h"
#include "../DAL/leavedal.h"
#include <QObject>
Leave::Leave()
{
}
Leave::Leave(int id, QDate ldate, QDate rdate, int payType, int employeeid)
{
    setId(id);
    setLeaveDate(ldate);
    setRequestDate(rdate);
    setPayType(payType);
    setEmployeeId(employeeid);
}
bool Leave::AddToStorage(QString & MessageError)
{
    if(getLeaveDate()>QDate::currentDate())
    {
        MessageError=QObject::tr("leave date has gone ! try again !");
        return false;
    }
    LeaveDal::addLeave(this,MessageError);
}

QString Leave::paidTypeMapper(int x)
{
    switch(x)
    {
    case 0:
        return " Full Paid";
        break;
    case 1:
        return "Half Paid";
        break;
    case 2:
        return "Unpaid";
        break;
    }
}


//setters
void Leave::setId(int id)
{
    this->id=id;
}

void Leave::setEmployeeId(int empid)
{
    this->employeeid=empid;
}

void Leave::setLeaveDate(QDate ldate)
{
    this->leaveDate=ldate;
}

void Leave::setRequestDate(QDate rdate)
{
   this->requestDate=rdate;
}

void Leave::setPayType(int payType)
{
    this->payType=payType;
}

//getters
int Leave::getId()
{
    return id;
}

QDate Leave::getRequestDate()
{
    return requestDate;
}

QDate Leave::getLeaveDate()
{
    return leaveDate;
}

int Leave::getEmployeeId()
{
    return employeeid;
}

int Leave::getPayType()
{
    return payType;
}
