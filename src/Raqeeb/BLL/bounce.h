#ifndef BOUNCE_H
#define BOUNCE_H
#include <QDate>
class bounce
{
public:
    bounce();
private:
    int amount;
    int empid;
    int done;
    QDate addate;
    QDate paydate;
    int type;
public:
    bool addToStorage(QString& error);
    // getters
    int getAmount();
    int getEmpId();
    int getDone();
    QDate getAddDate();
    QDate getPayDate();
    int getType();
    // setters
    void setAmount(int amount);
    void setEmpId(int empid);
    void setDone(int done);
    void setAddDate(QDate date);
    void setPayDate (QDate date);
    void setType(int type);
};

#endif // BOUNCE_H
