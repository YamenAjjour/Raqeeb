#include "leave.h"
#include "../DAL/leavedal.h"
#include <QObject>
Leave::Leave()
{
}
Leave::Leave(int id, QDate ldate, QDate edate, QDate rdate, int payType, QVector<int> employeeids)
{
    setId(id);
    setLeaveDate(ldate);
    setRequestDate(rdate);
    setEndDate(edate);
    setPayType(payType);
    setEmployeeIds(employeeids);
}
bool Leave::AddToStorage(QString & MessageError)
{
    if(!LeaveDal::addLeave(this))
    {
        MessageError=LeaveDal::getLastError();
    }
    else
        return true;
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

bool Leave::update()
{
    if(!LeaveDal::updateLeave(*this))
            throw QString(LeaveDal::getLastError());
    return true;
}

bool Leave::deleteMe()
{
    if(!LeaveDal::deleteLeave(*this))
        throw QString(LeaveDal::getLastError());
    return true;
}


//setters
void Leave::setId(int id)
{
    this->id=id;
}

void Leave::setEmployeeIds(QVector<int>& empids)
{
    this->employeeids=empids;
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
void Leave::setEndDate(QDate edate)
{
    this->endDate = edate;
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

const QVector<int> &Leave::getEmployeeIds()
{
    return employeeids;
}

int Leave::getPayType()
{
    return payType;
}

QDate Leave::getEndDate()
{
    return this->endDate;
}
