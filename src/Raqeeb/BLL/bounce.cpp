#include "bounce.h"
#include "../DAL/bouncedal.h"
bounce::bounce()
{
}

bool bounce::addToStorage(QString& error)
{
    bounceDAL::addbounce(this,error);
}

void bounce::setAddDate(QDate date)
{
    this->addate=date;
}

void bounce::setAmount(int amount)
{
    this->amount=amount;
}

void bounce::setDone(int done)
{
    this->done=done;
}

void bounce::setEmpId(int empid)
{
    this->empid=empid;
}

void bounce::setPayDate(QDate date)
{
    this->paydate=date;
}

void bounce::setType(int type)
{
    this->type=type;
}

int bounce::getEmpId()
{
    return empid;
}

int bounce::getAmount()
{
    return amount;
}

QDate bounce::getAddDate()
{
    return addate;
}

QDate bounce::getPayDate()
{
    return addate;
}

int bounce::getDone()
{
    return done;
}

int bounce::getType()
{
    return type;
}
