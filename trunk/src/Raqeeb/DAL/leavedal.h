#ifndef LEAVEDAL_H
#define LEAVEDAL_H
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDate>
class Leave;

class LeaveDal
{
private :
    static QSqlQuery *q;
    static QString lastError;
public:
    LeaveDal();
    static bool addLeave(Leave* l);
    static bool getAllLeave(QList<Leave *> &leaves,int empid=-1);
    static bool getLeaveByDate (int machineid , QDate sdate, QDate edate , QList<Leave*>& leaves);
    static QString getLastError();
    static bool updateLeave(Leave l);
    static bool deleteLeave(Leave l );
    static bool removeLeave(int);
    static bool initQuery();
    static void finalizeQuery();
};

#endif // LEAVEDAL_H
