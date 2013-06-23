#include "leavedal.h"
#include <QList>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include<QVariant>
#include "../BLL/leave.h"
QSqlError LeaveDal::error;
LeaveDal::LeaveDal()
{
}
QSqlError LeaveDal::getLastError()
{
    return error;
}

void LeaveDal::setError(QSqlError err)
{
        error=err;
}

bool LeaveDal::addLeave(Leave *l,QString &messageError)
{
    QSqlDatabase db = QSqlDatabase::database("rdb");
    if(db.open())
    {
        QSqlQuery query(db);
        query.prepare("select addleave(:ldate,:rdate,:paytype,:empid);");
        query.bindValue(":ldate",l->getLeaveDate());
        query.bindValue(":rdate",l->getRequestDate());
        query.bindValue(":ispaid",l->getPayType());
        query.bindValue(":empid",l->getEmployeeId());
        bool result= query.exec();
        if(!result)
        {
            messageError="error in query"+query.lastError().text();
            return false;

        }
        query.next();
        if(query.value(0).toBool())
        {
            return true;
        }
        else
        {
            messageError="Employee doesn't existed !";
            return false;
        }
        setError(query.lastError());
        return result;
    }
    messageError="cannot connect to database";
    return false;
}

bool LeaveDal::addLeaveToAllEmp(Leave *l,QString &messageError)
{
    QSqlDatabase db = QSqlDatabase::database("rdb");
    if(db.open())
    {
        QSqlQuery query(db);
        query.prepare("select addleavetoall(:ldate,:rdate,:paytype);");
        query.bindValue(":ldate",l->getLeaveDate());
        query.bindValue(":rdate",l->getRequestDate());
        query.bindValue(":ispaid",l->getPayType());
        bool result= query.exec();
        if(!result)
        {
            messageError="error in query"+query.lastError().text();
            return false;

        }
        if(query.value(0).toBool())
        {
            return true;
        }
        else
        {
            messageError="No Employee found!";
            return false;
        }
        setError(query.lastError());
        return result;
    }
    messageError="cannot connect to database";
    return false;
}

 bool LeaveDal::getAllLeave(QList<Leave>& leaves,int empid)
{
    leaves.clear();
    QSqlDatabase db = QSqlDatabase::database("rdb");
    if(db.open())
    {
        QSqlQuery query(db);
        if(empid!=-1)
        {
            query.prepare("select * from getleavebyid(:empid)");
            query.bindValue(":empid",empid);
        }
        else
            query.prepare("select * from leave");

        bool result= query.exec();
        if(!result)
        {
            setError(query.lastError());
            return result;
        }
        while(query.next())
        {
            Leave l;
            l.setId(query.value(0).toInt());
            l.setLeaveDate(query.value(1).toDate());
            l.setRequestDate(query.value(2).toDate());
            l.setPayType(query.value(3).toInt());
            leaves.append(l);
        }
        return true;
    }
    setError(db.lastError());
    return false;
}

 bool LeaveDal::updateLeave(int id , Leave l)
 {
     QSqlDatabase db = QSqlDatabase::database("rdb");
     if(db.open())
     {
         QSqlQuery query(db);
         query.prepare("select updateLeave(:id,:ldate,:rdate,:paytype)");
         query.bindValue(":id",l.getId());
         query.bindValue(":ldate",l.getLeaveDate());
         query.bindValue(":rdate",l.getRequestDate());
         query.bindValue(":paytype",l.getPayType());
         bool result =query.exec();
         if(!result)
             return result;
         setError(query.lastError());
     }
 }

 bool LeaveDal::removeLeave(int id)
 {
     QSqlDatabase db = QSqlDatabase::database("rdb");
     if(db.open())
     {
         QSqlQuery query(db);
         query.prepare("delete from leave where id = :id");
         if(query.exec())
             return true;
         else
         {
             setError(query.lastError());
             return false;
         }
     }
     setError(db.lastError());
     return false;
 }
