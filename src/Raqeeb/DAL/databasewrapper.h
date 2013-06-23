#ifndef DATABASEWRAPPER_H
#define DATABASEWRAPPER_H
#include <QString>
#include <QtSql/QSqlDatabase>
#include "../BLL/user.h"
class databaseWrapper
{
private:
     static databaseWrapper* single;
     databaseWrapper(QString server ,QString userName,QString password,QString db);
     QString userName;
     QString password;
     QString dbName;
     QSqlDatabase* db;
     QString server;
     bool isConnected;
     static bool instanceFlag;

public:
     QSqlDatabase* connect();
    static databaseWrapper* getInstance();
     void disconnect();
     ~databaseWrapper();
};




#endif // DATABASEWRAPPER_H
