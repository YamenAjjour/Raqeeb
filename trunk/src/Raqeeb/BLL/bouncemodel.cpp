#include "bouncemodel.h"
#include "../DAL/bouncedal.h"
#include "../BLL/bounce.h"
#include <QStringList>
bounceModel::bounceModel( int type , int empid ,QObject *parent ) :
    QStandardItemModel(parent)
{
    initialize(type,empid);
}

void bounceModel::initialize(int type , int empid)
{
    setType(type);
    setEmpid(empid);
    QList<QStandardItem*> items;
    QList<bounce*> bounces;
    if(!bounceDAL::getBounces(getEmpid(),geType(),bounces))
        throw bounceDAL::getLastError();
    foreach(bounce * b ,bounces)
    {
        prepareBounce(b,items);
        appendRow(items);
        items.clear();
    }
    QStringList headers;
    headers.append(tr("Amount"));
    headers.append(tr("Date Requested"));
    headers.append(tr("Payment Date"));
    headers.append(tr("Done"));
    setHorizontalHeaderLabels(headers);
}

void bounceModel::finalize()
{
}

void bounceModel::setType(int type)
{
    this->type= type;
}

int bounceModel::getEmpid()
{
    return empid;
}

bool bounceModel::addBounce(bounce *b)
{
    b->addToStorage();
    QList<QStandardItem*> items;
    prepareBounce(b,items);
    appendRow(items);
    forceDataChange();
}

int bounceModel::geType()
{
    return type;
}

void bounceModel::setEmpid(int empid)
{
    this->empid = empid;
}

bool bounceModel::removeBounce(bounce *b,int row)
{
    b->deleteMe();
    removeRow(row);
    forceDataChange();
    forceDataChange();
}

void bounceModel::prepareBounce(bounce *b, QList<QStandardItem *> &items)
{
    QStandardItem* item;
    item = new QStandardItem();
    item->setTextAlignment(Qt::AlignCenter);
    item->setData(b->getAmount(),Qt::DisplayRole);
    items<<item;
    item= new QStandardItem();
    item->setTextAlignment(Qt::AlignCenter);
    item->setData(b->getAddDate(),Qt::DisplayRole);
    items<<item;
    item = new QStandardItem();
    item->setTextAlignment(Qt::AlignCenter);
    item->setData(b->getPayDate(),Qt::DisplayRole);
    items<<item;
    item = new QStandardItem();
    item->setTextAlignment(Qt::AlignCenter);
    item->setData(b->getDone(),Qt::DisplayRole);
    items<<item;
}

void bounceModel::forceDataChange()
{
    QModelIndex b = index(0,0);
    emit dataChanged(b,b);
}
