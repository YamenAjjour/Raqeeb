#include "bouncedal.h"
#include <QSqlQuery>
#include "../BLL/bounce.h"
#include <QVariant>
bounceDAL::bounceDAL()
{
}

bool bounceDAL::addbounce(bounce *b, QString &errorMessage)
{
    QSqlDatabase db = QSqlDatabase::database("rdb");
    if(db.open())
    {
        QSqlQuery query(db);
        query.prepare("select addBounce(:amount,:empid,:done,:adddate,:paydate,:type);");
        query.bindValue(":amount",b->getAmount());
        query.bindValue(":empid",b->getEmpId());
        query.bindValue(":done",b->getDone());
        query.bindValue(":adddate",b->getAddDate());
        query.bindValue(":paydate",b->getPayDate());
        query.bindValue(":type",b->getType());

        bool result= query.exec();
        if(!result)
        {
            errorMessage="error in query"+query.lastError().text();
            return false;

        }
        query.next();
        if(query.value(0).toBool())
        {
            return true;
        }
        else
        {
            errorMessage="Employee doesn't existed !";
            return false;
        }
        setLastError(query.lastError());
        return result;
    }
    errorMessage="cannot connect to database";
    return false;
}
