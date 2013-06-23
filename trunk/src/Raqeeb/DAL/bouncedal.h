#ifndef BOUNCEDAL_H
#define BOUNCEDAL_H
#include <QSqlError>
#include <QList>
class bounce;
class bounceDAL
{
private:
    static QString lastError;
public:
    bounceDAL();
    static bool addbounce(bounce* b);
    static bool deleteBounce(bounce* b);
    static bool getBounces(int empid , int type, QList<bounce *> &bounces);
    static QString getLastError();
    static void setLastError();

};

#endif // BOUNCEDAL_H
