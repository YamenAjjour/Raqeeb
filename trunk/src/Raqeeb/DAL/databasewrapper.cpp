#include "databasewrapper.h"
#include <QtSql/QSqlQuery>


bool databaseWrapper::instanceFlag =false;
databaseWrapper* databaseWrapper::single=NULL;

databaseWrapper::databaseWrapper(QString server,QString userName, QString password, QString db)
{
    this->userName=userName;
    this->password=password;
    this->server=server;
    this->dbName=db;
    isConnected=false;
    db=null;
}


static databaseWrapper* databaseWrapper::getInstance()
{
    if(!instanceFlag)
    {
        single = new databaseWrapper("localhost","postgres","0","rdb");
        instanceFlag =true;
    }
    return single;
}

// return the connection if established null otherwise
QSqlDatabase* databaseWrapper::connect()
{
    if(db)
        return db;
    QSqlDatabase* db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(server);
    db.setDatabaseName(dbName);
    db.setUserName(userName);
    db.setPassword(password);
    isConnected = db->open();
    return db;
}


void databaseWrapper::disconnect()
{
    delete db;
}


~databaseWrapper()
{
    instanceFlag=false;
}


