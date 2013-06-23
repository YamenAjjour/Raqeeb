#include "userhandler.h"
#include <QFile>
#include <QDataStream>
#include "user.h"
#include <QStringList>
#include <QStandardItem>
#include <QString>
#include<QMapIterator>
#include <QTextStream>
#include "../DAL/userDAL.h"
#include <QVariant>
UserHandler::UserHandler(QObject *parent) :
    QStandardItemModel(parent)
{
    setColumnCount(6);
    QStringList headers;
    headers.append(tr("Id"));
    headers.append(tr("First Name"));
    headers.append(tr("Last Name"));
    headers.append(tr("Email"));
    headers.append(tr("Mobile"));
    headers.append(tr("HourPrice"));
    setHorizontalHeaderLabels(headers);
}

bool UserHandler::init(QString &MessageError)
{
    users.clear();
    clear();
    if(!UserDal::getAllUser(users))
    {
        MessageError=UserDal::getLastError().text();
        return false;
    }
    QList<User>::Iterator it=users.begin();
    QList<QStandardItem*> items;
    QStandardItem* item;

    for(it;it!=users.end();it++)
    {
        item = new QStandardItem();
        item->setTextAlignment(Qt::AlignCenter);
        item->setData((*it).getId(),Qt::EditRole);
        items<<item;
        item = new QStandardItem();
        item->setData((*it).getFirstName(),Qt::DisplayRole);
        item->setTextAlignment(Qt::AlignCenter);
        items<<item;
        item = new QStandardItem();
        item->setData((*it).getLastName(),Qt::DisplayRole);
        item->setTextAlignment(Qt::AlignCenter);
        items<<item;
        item = new QStandardItem();
        item->setData((*it).getEmail(),Qt::DisplayRole);
        item->setTextAlignment(Qt::AlignCenter);
        items<<item;
        item = new QStandardItem();
        item->setData((*it).getMobile(),Qt::DisplayRole);
        item->setTextAlignment(Qt::AlignCenter);
        items<<item;
        item = new QStandardItem();
        item->setData((*it).getHourPrice(),Qt::DisplayRole);
        item->setTextAlignment(Qt::AlignCenter);
        items<<item;
        appendRow(items);
        items.clear();
    }


    return true;
}

bool UserHandler::finalize()
{
    this->clear();
    users.clear();
}
int UserHandler::getUserInfo(int id,QPair<QString,double>& data)
{
    QModelIndexList ind=  match(index(0,0),Qt::EditRole,QVariant(id));
    if(ind.count()>0)
    {
        data.first = this->item(ind[0].row(),E_NAME)->data(Qt::DisplayRole).toString();
        data.second=this->item(ind[0].row(),5)->data(Qt::DisplayRole).toDouble();
        return 1;
    }
    else
        return 0;
}

void UserHandler::forceChangeData()
{
    QModelIndex b = index(0,0);
    emit dataChanged(b,b);
}


