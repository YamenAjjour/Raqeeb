#include "empidmodel.h"
#include <QList>
#include "../DAL/userdal.h"
#include "../BLL/user.h"
empidModel::empidModel(QObject *parent) :
    QStandardItemModel(parent)
{
    size=0;
}

bool empidModel::AddItem(QString name, int id)
{
    if(contains(name))
        return false;
    QStandardItem* item = new QStandardItem(name);
    item->setData(id,Qt::UserRole);
    QList<QStandardItem*> items;
    items.append(item);
    appendRow(items);
    size++;
}

bool empidModel::RemoveItem(QModelIndex index)
{
        size--;
    return removeRow(index.row());
}

bool empidModel::contains(QString name)
{
    for(int i=0;i<this->size;i++)
    {
        if(this->item(i,0)->data(Qt::DisplayRole).toString()==name)
            return true;
    }
    return false;
}

void empidModel::getCurrentIds(QList<int>& ids)
{
    for(int i =0;i<this->size;i++)
    {
        ids.append(this->item(i,0)->data(Qt::UserRole).toInt());
    }
}

void empidModel::fill()
{
    QList<User> users;
    UserDal::getAllUser(users);
    for(int i=0;i<users.count();i++)
    {
        AddItem(users[i].getFirstName(),users[i].getId());
    }
}

void empidModel::clear()
{
    size=0;
    clear();
}
