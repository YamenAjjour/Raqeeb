#ifndef FILEHANDLER_H
#define FILEHANDLER_H
 #include <QList>
#include "user.h"
#include <QString>
#include <QFile>
#include "log.h"
#include <QTextStream>
class FileHandler
{
public:
    QFile* CF;
    FileHandler(QString fileName);
    bool getUsers(QList<User>& users);
    ~FileHandler();
    bool isValid;
private:
    int CI;
    QString CL;
    bool openFile(QString fileName);
    bool readLine();
    void closeFile();
    bool getToken(QString& token);
    bool skipSpaces();
    bool getLog(Log &lg,int &usderId);
    QTextStream *in;
};

#endif // FILEHANDLER_H
