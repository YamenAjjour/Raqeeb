#include "userdal.h"
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QtSql/QSqlDatabase>
#include"../BLL/User.h"
QSqlError UserDal::error;
UserDal::UserDal()
{
}

void UserDal::setError(QSqlError err)
{
    error =err;
}

QSqlError UserDal::getLastError()
{
    return UserDal::error;
}

bool UserDal::addUser(User* u,QString & messageError)
{
    QSqlDatabase db = QSqlDatabase::database("rdb");
    if(db.open())
    {
        QSqlQuery query(db);
        query.prepare("select addemployee( :id, :fn, :ln, :email, :phone, :aemail ,:mobile,:hprice);");
        query.bindValue(":id",u->getId());
        query.bindValue(":fn",u->getFirstName());
        query.bindValue(":ln",u->getLastName());
        query.bindValue(":email",u->getEmail());
        query.bindValue(":phone",u->getPhone());
        query.bindValue(":aemail",u->getAnotherEmail());
        query.bindValue(":mobile",u->getMobile());
        query.bindValue(":hprice",u->getHourPrice());
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
            messageError="Employee already existed with the same id or name";
            return false;
        }
        setError(query.lastError());
        return result;
    }
    messageError="cannot connect to database";
    return false;
}

bool  UserDal::getAllUser(QList<User>& users)
{
    QSqlDatabase db = QSqlDatabase::database("rdb");
    if(db.open())
    {
        QSqlQuery query(db);
        query.prepare("select * from emp");
        query.exec();
        while(query.next())
        {
            User u;
            u.setId(query.value(0).toInt());
            u.setFirstName(query.value(1).toString());
            u.setLastName(query.value(2).toString());
            u.setEmail(query.value(3).toString());
            u.setPhone(query.value(4).toString());
            u.setAnotherEmail(query.value(5).toString());
            u.setMobile(query.value(6).toString());
            u.setHourPrice(query.value(7).toDouble());
            users.append(u);
        }
        return true;
    }
    setError(db.lastError());
    return false;
}

 bool UserDal::getUserById(int id , User& u)
{
    QSqlDatabase db = QSqlDatabase::database("rdb");
    bool result = false;
    if(db.open())
    {
        QSqlQuery query(db);
        query.prepare("select * from emp where empid =:id");
        query.bindValue(":id",id);
        while(query.next())
        {
            result=true;
            u.setId(query.value(0).toInt());
            u.setFirstName(query.value(1).toString());
            u.setLastName(query.value(2).toString());
            u.setEmail(query.value(3).toString());
            u.setPhone(query.value(4).toString());
            u.setAnotherEmail(query.value(5).toString());
            u.setMobile(query.value(6).toString());
            u.setHourPrice(query.value(7).toDouble());
            break;
        }
        setError(query.lastError());
        return result;
    }
    return false;
}

 bool UserDal::getAllUserStartBy(QString &prefix,QVector<User>& users)
{
    QSqlDatabase db = QSqlDatabase::database("rdb");
    bool result = false;
    if(db.open())
    {
        QSqlQuery query(db);
        query.prepare("select empid,name from emp where firstname like :prefix+'%'");
        query.bindValue(":prefix",prefix);
        while(query.next())
        {
            User u;
            result=true;
            u.setId(query.value(0).toInt());
            u.setFirstName(query.value(1).toString());
            users.append(u);

        }
        setError(query.lastError());
        return result;
    }
    return false;
}
