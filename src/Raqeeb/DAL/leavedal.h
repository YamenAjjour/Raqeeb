#ifndef LEAVEDAL_H
#define LEAVEDAL_H
#include <QtSql/QSqlError>


class Leave;

class LeaveDal
{
private :
    static QSqlError error;
public:
    LeaveDal();
    static bool addLeave(Leave* l,QString &messageError);
    static bool getAllLeave(QList<Leave>& leaves,int empid=-1);
    static bool addLeaveToAllEmp(Leave *l,QString &messageError);
    static QSqlError getLastError();
    static void setError(QSqlError err);
    static bool updateLeave(int id , Leave l);
    static bool removeLeave(int);
};

#endif // LEAVEDAL_H
