#include "leavemodel.h"
#include "../DAL/leavedal.h"
#include "leave.h"
leavemodel::leavemodel(QObject *parent,int employeeid) :
    QStandardItemModel(parent)
{
    this->employeeid=employeeid;
}

void leavemodel::init()
{
    clear();
    size=0;
    QList<Leave> leaves;
    LeaveDal::getAllLeave(leaves,employeeid);
    QList<Leave>::iterator it = leaves.begin();
    for(it;it!=leaves.end();it++)
    {
        addItem(*it);
    }
}

bool leavemodel::addItem(Leave& l)
{
    size++;
    QStandardItem * itemId = new QStandardItem(QString(l.getId()));
    QStandardItem * itemLeaveDate = new QStandardItem(l.getLeaveDate().toString());
    QStandardItem * itemPayType = new QStandardItem(Leave::paidTypeMapper(l.getPayType()));
    QStandardItem * itemReqDate = new QStandardItem(QString(l.getRequestDate().toString()));
    QList<QStandardItem*> items;
    items.append(itemId);
    items.append(itemLeaveDate);
    items.append(itemPayType);
    items.append(itemReqDate);
    appendRow(items);
}

bool leavemodel::updateLeave(int id ,Leave& l)
{
    for(int i =0;i<size;i++)
    {
        if(item(i,U_ID)->data()==id)
        {
            item(i,U_REQUEST_DATE)->setData(l.getRequestDate());
            item(i,U_LEAVE_DATE)->setData(l.getLeaveDate());
            item(i,U_PAY_TYPE)->setData(l.getPayType());
            LeaveDal::updateLeave(id,l);
        }
    }
}

bool leavemodel::removeItem(int id,QString & errorMessage)
{
    for(int i=0;i<size;i++)
    {
        if(item(i,U_ID)->data()==id)
        {
            removeRow(id);
            if(LeaveDal::removeLeave(i))
            {
                errorMessage=LeaveDal::getLastError().text();
            }
        }
    }
}
