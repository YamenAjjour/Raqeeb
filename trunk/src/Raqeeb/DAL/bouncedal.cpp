#include "bouncedal.h"
#include <QSqlQuery>
#include "../BLL/bounce.h"
#include <QVariant>
#include <QDebug>
QString bounceDAL::lastError="";
bounceDAL::bounceDAL()
{
}

bool bounceDAL::addbounce(bounce *b)
{
    QSqlDatabase db = QSqlDatabase::database("employee.dat");
    bool result=false;
    if(db.open())
    {
        QSqlQuery query(db);
        query.prepare("insert into bouncededuction (amount,empid,done,adddate,paydate,type) values (:amount,:empid,:done,:adddate,:paydate,:type);");
        query.bindValue(":amount",b->getAmount());
        query.bindValue(":empid",b->getEmpId());
        query.bindValue(":done",b->getDone());
        query.bindValue(":adddate",b->getAddDate());
        query.bindValue(":paydate",b->getPayDate());
        query.bindValue(":type",b->getType());
        result= query.exec();
        if(!result)
        {
            lastError=query.lastError().text();
            return false;
        }
        else
            return true;

    }
    lastError = "Database is missing ! ";
    return false;
}

bool bounceDAL::deleteBounce(bounce *b)
{
    QSqlDatabase db= QSqlDatabase::addDatabase("employee.dat");
    bool result =false;
    if(db.open())
    {
        QSqlQuery query(db);
        query.prepare("delete from bouncededuction where bounceid = :bid");
        query.bindValue(":bid",b->getId());
        result = query.exec();
        if(!result)
        {
            lastError = query.lastError().text();
            return false;
        }else
            return true;
    }
    else
    {
        lastError = "Database is missing ! ";
        return false;
    }
}

bool bounceDAL::getBounces(int empid , int type , QList<bounce*> &bounces)
{
    QSqlDatabase db= QSqlDatabase::database("employee.dat");
    if(db.open())
    {
        QSqlQuery query(db);
        query.prepare("select amount , empid ,done ,adddate ,paydate , type from bouncededuction where empid = :empid and type =:type");
        query.bindValue(":empid",empid);
        query.bindValue(":type",type);
        if(!query.exec())
        {
            lastError = query.lastError().text();
            qDebug()<<lastError;
            return false;
        }
        while(query.next())
        {
            bounce * b= new bounce();
            b->setAmount(query.value(0).toDouble());
            b->setEmpId(query.value(1).toInt());
            b->setDone(query.value(2).toInt());
            b->setAddDate(query.value(3).toDate());
            b->setPayDate(query.value(4).toDate());
            b->setType(query.value(5).toInt());
            bounces.append(b);
        }
        return true;
    }
    else
    {
        lastError = "Database is missing !";
        return false;
    }
}


QString bounceDAL::getLastError()
{
    return lastError;
}

