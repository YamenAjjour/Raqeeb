#ifndef BOUNCEDAL_H
#define BOUNCEDAL_H
#include <QSqlError>
class bounce;
class bounceDAL
{
public:
    bounceDAL();
    static bool addbounce(bounce* b,QString & errorMessage);
    static QSqlError getLastError();
    static void setLastError(QSqlError err);
};

#endif // BOUNCEDAL_H
