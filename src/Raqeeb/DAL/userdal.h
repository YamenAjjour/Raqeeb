#ifndef USERDAL_H
#define USERDAL_H
#include <QtSql/QSqlError>
#include <QVector>
#include <QString>
class User;
class UserDal
{
private:
    static QSqlError  error;
public:
    UserDal();
    static bool addUser(User* u,QString &messageError);
    static bool getAllUser(QList<User>& users);
    static bool getUserById(int id, User& u);
    static QSqlError getLastError();
    static void setError(QSqlError err);
    static bool getAllUserStartBy(QString &prefix,QVector<User>& users);
};

#endif // USERDAL_H
