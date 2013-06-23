#ifndef LOG_H
#define LOG_H
#include <QDate>
#include <QTime>
class Log
{

public:
    Log(QDate date , int type,int status,QTime time);
    Log();

    int setStatus(int status){this->status=status;}
    void setDate(QDate date){this->date=date;}
    void setType(int type){this->type=type;}
    void setTime(QTime time){this->time=time;}

    bool operator ==(const Log& other) const {return date.day()==other.getDate().day();}

    QDate getDate()const{return date;}
    int getStatus()const{return status;}
    QTime getTime()const{return time;}
    int getType()const{return type;}

    int getMins(){return (getTime().hour()*60 + getTime().minute());}
private:
   QDate date;
   int type;
   QTime time;
   int status;
};

#endif // LOG_H
