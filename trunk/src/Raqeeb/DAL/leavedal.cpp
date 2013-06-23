#include "leavedal.h"
#include <QList>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include<QVariant>
#include "../BLL/leave.h"
#include <QStringBuilder>
#include <QDebug>
#include <QMapIterator>
QSqlQuery* LeaveDal::q = NULL;
QString LeaveDal::lastError=QString("");
LeaveDal::LeaveDal()
{

}
QString LeaveDal::getLastError()
{
    if(q)
        return lastError;
    else
        return QString();
}


bool LeaveDal::addLeave(Leave *l)
{
    if(l->getEmployeeIds().count()<1)
        throw QString("an employee at least must be chosen ");
    if(initQuery())
    {
        QSqlDatabase db = QSqlDatabase::database("employee.dat");
        bool result = false;
        q->boundValues().clear();
        QString cmd = "insert into leave(leavedate,enddate,reqdate,paid) values(:ldate,:edate,:rdate,:ispaid)" ;
        q->clear();
        q->prepare(cmd);
        q->bindValue(":ldate",l->getLeaveDate());
        q->bindValue(":rdate",l->getRequestDate());
        q->bindValue(":edate",l->getEndDate());
        q->bindValue(":ispaid",l->getPayType());
        if(!db.transaction())
            return false;
        try
        {
            if(!q->exec())
            {
               qDebug()<<q->lastQuery();
               qDebug()<<q->lastError().text();
               QMapIterator<QString, QVariant> i(q->boundValues());
                   while (i.hasNext()) {
                       i.next();
                       qDebug() << i.key().toAscii().data() << ": "
                            << i.value().toString().toAscii().data() << endl;
                 }
               db.rollback();
               finalizeQuery();
               return false;
            }
            q->clear();
            cmd = "select max(id) from leave ";
            q->prepare(cmd);
            if(!q->exec())
            {
                db.rollback();
                finalizeQuery();
                return false;
            }
            q->next();
            int leaveid = q->value(0).toInt();
            int employeeid ;
            foreach(employeeid, l->getEmployeeIds())
            {
                q->clear();
                cmd="insert into emp_leave(empid,leaveid) values (:empid,:leaveid)";
                q->prepare(cmd);
                q->bindValue(":empid",employeeid);
                q->bindValue(":leaveid",leaveid); // well this is stupied because there is only just one leave but the problem is you cannot useq the same parm in a query more than one time !
                if(!q->exec())
                {
                    db.rollback();
                    finalizeQuery();
                    return false;
                }

            }
            result = db.commit();
            finalizeQuery();
            return result;
        }
        catch(char*)
        {
            db.rollback();
            finalizeQuery();
            return false;
        }
    }
    return false;
 }
 bool LeaveDal::getAllLeave(QList<Leave*>& leaves,int empid)
{
    leaves.clear();
    if(initQuery())
    {
        if(empid!=-1)
        {
            q->prepare("select id,leavedate,reqdate,paid,enddate from leave inner join emp_leave on leave.id=emp_leave.leaveid  where empid=:empid");
            q->bindValue(":empid",empid);
        }
        else
            q->prepare("select id,leavedate,reqdate,paid,enddate from leave");

        bool result= q->exec();
        if(!result)
        {
            finalizeQuery();
            return result;
        }
        while(q->next())
        {
            Leave *l = new Leave();
            l->setId(q->value(0).toInt());
            l->setLeaveDate(q->value(1).toDate());
            l->setRequestDate(q->value(2).toDate());
            l->setPayType(q->value(3).toInt());
            l->setEndDate(q->value(4).toDate());
            QVector<int> empids;
            empids.append(empid);
            l->setEmployeeIds(empids);
            leaves.append(l);
        }
        finalizeQuery();
        return true;
    }
    finalizeQuery();
    return false;
 }

 bool LeaveDal::getLeaveByDate(int machineid, QDate sdate , QDate edate , QList<Leave*>& leaves)
 {
     leaves.clear();
     bool result ;
     if(initQuery())
     {
         if(machineid==-1)
         {
             q->prepare("select id,leavedate,reqdate,paid,enddate from leave where( (leavedate >= :sdate or enddate >= :sdate) and (leavedate <= :edate or enddate <= :edate ))");
         }
         else
            q->prepare("select id,leavedate,reqdate,paid,enddate from leave inner join emp_leave on leave.id=emp_leave.leaveid  where empid=:empid and ( (leavedate >= :sdate or enddate >= :sdate) and (leavedate <= :edate or enddate <= :edate ))");
         q->bindValue(":empid",machineid);
         q->bindValue(":sdate",sdate);
         q->bindValue(":edate",edate);
         bool result = q->exec();
         if(!result)
         {
             finalizeQuery();
             return result;
         }
         while(q->next())
         {
             Leave *l = new Leave();
             l->setId(q->value(0).toInt());
             l->setLeaveDate(q->value(1).toDate());
             l->setRequestDate(q->value(2).toDate());
             l->setPayType(q->value(3).toInt());
             l->setEndDate(q->value(4).toDate());
             leaves.append(l);
         }
         finalizeQuery();
         return true;
     }
 }

 bool LeaveDal::updateLeave( Leave l)
 {
     bool result;
     if(initQuery())
     {
         q->prepare("update leave set leavedate = :ldate,enddate=:edate,reqdate=:rdate,paid=:paytype where id=:id");
         q->bindValue(":id",l.getId());
         q->bindValue(":ldate",l.getLeaveDate());
         q->bindValue(":rdate",l.getRequestDate());
         q->bindValue(":paytype",l.getPayType());
         q->bindValue(":edate",l.getEndDate());
         result = q->exec();
         qDebug()<<l.getId()<<" "<<l.getEndDate()<<"  "<<l.getLeaveDate()<<" "<<l.getPayType()<<" "<<l.getRequestDate();
         finalizeQuery();
         return result;
     }
     else
     {
         finalizeQuery();
         return false;
     }
 }

 bool LeaveDal::deleteLeave(Leave l)
 {
     bool result=false;
     if(initQuery())
     {
         q->prepare("delete from leave where id = :id");
         q->bindValue(":id",l.getId());
         result = q->exec();
         finalizeQuery();
         return result;
     }
     else
     {
         finalizeQuery();
         return false;
     }
 }


 bool LeaveDal::removeLeave(int id)
 {
     QSqlDatabase db = QSqlDatabase::database("rdb");
     bool result;
     if(db.open())
     {
         q->prepare("delete from leave where id = :id");
         result = q->exec();
         finalizeQuery();
         return result;
     }
     finalizeQuery();
     return false;
 }

 bool LeaveDal::initQuery()
 {
     QSqlDatabase db = QSqlDatabase::database("employee.dat");
     if(db.open())
     {
         if(q)
             finalizeQuery();
         q = new QSqlQuery(db);
         return true;
     }
     else
         return false;
 }

 void LeaveDal::finalizeQuery()
 {
     lastError = q->lastError().text();
     delete q;
     q=NULL;
 }
