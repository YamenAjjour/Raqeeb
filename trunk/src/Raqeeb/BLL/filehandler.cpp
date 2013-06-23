#include "filehandler.h"
#include <QFileInfo>
#include <QFile>
#include <QVariant>
#include <QDate>
#include <QTime>
#include<QTextStream>
FileHandler::FileHandler(QString fileName)
{
    isValid=openFile(fileName);
    if(!isValid)
    {
        CF=NULL;
        in =NULL;
    }
}

bool FileHandler::openFile(QString fileName)
{
    CF = new QFile(fileName);
    if(!CF->open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return false;
    }
    in = new QTextStream(CF);
    return true;
}
 bool FileHandler::getUsers(QList<User>& users)
 {
    users.clear();
    Log lg;
    int userId;
    int result =getLog(lg,userId);
    User u;
    u.setMachineId(userId);
    while(result)
    {
        if(!users.contains(u))
        {
            users.append(u);
        }
      users[users.indexOf(u)].addLog(lg);
      result = getLog(lg,userId);
      u.setMachineId(userId);
    }
    foreach(User u,users)
    {
        for(int i =0;i<u.logs.count();i++)
        {
            if(i+1==u.logs.count())
                break;
            if(u.logs[i].getTime().secsTo(u.logs[i+1].getTime())<60)
                u.logs.remove(i+1);
        }
    }

    return false;

 }

 bool  FileHandler::getLog(Log &lg, int& userId)
 {
     static QString token;
     static int status;
     *in>>userId;
     if (in->status() == QTextStream::ReadPastEnd)
         return false;
     *in>>token;
     lg.setDate(QDate::fromString(token,"yyyy-MM-dd"));
     *in >> token;
     lg.setTime(QTime::fromString(token,"hh:mm:ss"));
     *in >>token; // Discard the fourth column ! what is it anyway ?
     *in >>status;
     lg.setStatus(status);
     *in>>token>>token;// Discard the the sixth and seventh columns !
     if(in->status() == QTextStream::ReadPastEnd || in->status() == QTextStream::ReadCorruptData)
         throw QString("Corrupted file ! the input file must be in the following format uid(int) date time int status(int) int int");
     return true;
 }
 FileHandler::~FileHandler()
 {
     if(CF!=NULL)
         delete CF;
     if(in !=NULL)
         delete in;
 }
