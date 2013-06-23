#ifndef USERDAL_H
#define USERDAL_H
#include <QtSql/QSqlQuery>
#include <QVector>
#include <QString>
class User;
class UserDal
{
private:
    static QSqlQuery *q;
    static QString lastError;
public:
    UserDal();
    static bool addUser(User* u,QString &messageError);
    static bool getAllUser(QList<User>& users);
    static bool getUserById(int id, User& u);
    static QSqlError getLastError();
    static bool initQuery();
    static void finalizeQuery();
    static bool getAllUserStartBy(QString &prefix,QVector<User>& users);
    static bool updateUser(User* u);
};

#endif // USERDAL_H
