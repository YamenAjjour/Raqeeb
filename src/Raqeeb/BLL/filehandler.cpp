#include "filehandler.h"
#include <QFileInfo>
#include <QFile>
#include <QVariant>
#include <QDate>
#include <QTime>
FileHandler::FileHandler(QString fileName)
{
    isValid=openFile(fileName);
    if(!isValid)
    {
        CF=NULL;
    }
}

bool FileHandler::openFile(QString fileName)
{
    CF = new QFile(fileName);
    if(!CF->open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return false;
    }

    return readLine();
}
bool FileHandler::readLine()
{
    if(CF==NULL)
        return false;
    if(!CF->atEnd())
    {
        CL=CF->readLine();
        CI=0;
        return true;
    }
    else
        return false;
}
bool FileHandler::skipSpaces()
{
    do
    {
        while((CI<CL.length())&&CL[CI].isSpace())
            CI++;
        if(CI>=CL.length())
        {
            if(!readLine())
                return false;
        }
        else
            return true;
    }while(true);

}
 bool FileHandler::getToken(QString& token)
{
    token.clear();
    if(skipSpaces())
    {
        while(!CL[CI].isSpace())
        {
            token.append(CL[CI]);
            CI++;
        }
        return true;
    }
    else
        return false;
}

 bool FileHandler::getUsers(QList<User>& users)
 {
    users.clear();
    Log lg;
    int userId;
    int result =getLog(lg,userId);
    User u;
    u.setId(userId);
    while(result==1)
    {
        if(!users.contains(u))
        {
            users.append(u);
        }
      users[users.indexOf(u)].addLog(lg);
      result = getLog(lg,userId);
      u.setId(userId);
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

    return result==2;

 }

 int  FileHandler::getLog(Log &lg, int& userId)
 {
     QString token;
     int i =0;
     while(true)
     {
         if(i==0)
         {
             if(getToken(token))
             {
                 QVariant userIdToken(token);
                 if(userIdToken.canConvert<int>())
                  {
                      userId=userIdToken.toInt();
                  }
                 else
                     return 0;
             }
             else
                 return 2;
         }
         else if(i==1)
         {
             if(getToken(token))
             {
                 QVariant dateToken(token);
                 if(dateToken.canConvert<QDate>())
                 {
                     lg.setDate(QDate::fromString(token,"yyyy-MM-dd"));
                 }
                 else
                     return 0;
             }
             else
                return 0;
         }
         else if(i==2)
         {
             if(getToken(token))
             {
                 QVariant timeToken(token);
                 if(timeToken.canConvert<QTime>())
                 {
                     lg.setTime(QTime::fromString(token,"hh:mm:ss"));
                 }
             }
             else
                return 0;
         }
         else if(i==3||i==5||i==6)
         {
             if(!getToken(token))
             {
                 return 0;
             }
             else
             {
                 QVariant intToken(token);
                 if(intToken.canConvert<int>())
                 {
                     if(i==6)
                     {
                         return 1;
                     }
                 }
                 else
                     return 0;
             }
         }
         else if(i==4)
         {
             if(getToken(token))
             {
                 QVariant statusToken(token);
                 if(statusToken.canConvert<int>())
                 {
                     lg.setStatus(statusToken.toInt());
                     if(lg.getStatus()>5)
                         return 0;
                 }
             }
             else
                 return 0 ;
         }
         i++;
     }
 }
 FileHandler::~FileHandler()
 {
     if(CF!=NULL)
         delete CF;
 }
