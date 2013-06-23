#include "bounce.h"
#include "../DAL/bouncedal.h"
#include <QMessageBox>
bounce::bounce()
{
}

bool bounce::addToStorage()
{
    if (!bounceDAL::addbounce(this))
        QMessageBox::warning(0,bounceDAL::getLastError(),bounceDAL::getLastError());
}

bool bounce::deleteMe()
{
    if(!bounceDAL::deleteBounce(this))
        QMessageBox::warning(0,bounceDAL::getLastError(),bounceDAL::getLastError());
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

void bounce::setId(int id)
{
    this->id = id;
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

int bounce::getId()
{
    return id ;
}
