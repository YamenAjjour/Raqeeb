#include "log.h"

Log::Log()
{

}

Log::Log(QDate date, int type,int status,QTime time)
{
    this->date=date;
    this->type=type;
    this->time=time;
    this->status=status;
}
