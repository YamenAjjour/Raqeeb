#ifndef USERHANDLER_H
#define USERHANDLER_H

#include <QtGui/QStandardItemModel>
#include <QString>
#include <QVector>
#include <QVariant>
#include "user.h"
#include "../DAL/databasewrapper.h"
enum Column {E_ID,E_NAME,E_LastName,E_Emai,E_Mobile,E_HOURPRICe};
const qint32 MagicNumber=0x5A697043;
const qint16 FormatNmber=100;
class UserHandler : public QStandardItemModel
{
    Q_OBJECT
public:
     UserHandler(QObject *parent = 0);
     bool init(QString &MessageError);
     bool finalize();
     int getUserInfo(int id ,QPair<QString,double>& data);
     void forceChangeData();
signals:

private:
     QList<User> users;
};

#endif // USERHANDLER_H
