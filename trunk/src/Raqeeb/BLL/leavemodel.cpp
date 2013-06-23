#include "leavemodel.h"
#include "../DAL/leavedal.h"
#include "leave.h"
#include <QList>
#include <QMessageBox>
#include <QDebug>
leavemodel::leavemodel(QObject *parent,int employeeid) :
    QAbstractTableModel(parent)
{
    this->employeeid=employeeid;
    LeaveDal::getAllLeave(leaves,employeeid);
    //emit dataChanged(index(0,0),index(leaves.count()-1,4));
}
bool leavemodel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && (role == Qt::EditRole ||role ==Qt::DisplayRole))
    {
         Leave *l = leaves.at(index.row());
        switch(index.column())
        {
        case U_REQUEST_DATE:
             l->setRequestDate(value.toDate());
            break;
        case U_LEAVE_DATE:
             l->setLeaveDate(value.toDate());
            break;
        case U_END_DATE:
             l->setEndDate(value.toDate());
            break;
        case U_PAY_TYPE:
             l->setPayType(value.toBool());
            break;
        default:
            break;

        }
        try
        {
        l->update();
        }
        catch(QString s)
        {
            QMessageBox::warning(0,s,s);
        }

        emit dataChanged(index,index);
        return true;
    }else
        return false;

}

QVariant leavemodel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    else if(role == Qt::DisplayRole || role == Qt::EditRole || role == Qt::ToolTip)
    {
        Leave *l =leaves.at(index.row());
        switch(index.column())
        {
        case U_REQUEST_DATE:
            return l->getRequestDate();
            break;
        case U_LEAVE_DATE:
            return l->getLeaveDate();
            break;
        case U_END_DATE:
            qDebug()<<l->getEndDate();
            return l->getEndDate();
            break;
        case U_PAY_TYPE:
            return l->getPayType();
            break;
        }

    }
    return QVariant();
}

int leavemodel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4;
}

int leavemodel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return leaves.count();
}

QVariant leavemodel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation==Qt::Horizontal && role==Qt::DisplayRole)
    {
        switch(section)
        {
        case U_LEAVE_DATE:
            return QString ("Leave Date");
            break;
        case U_END_DATE:
            return QString("End Date");
            break;
        case U_PAY_TYPE:
            return QString("Is Paid");
            break;
        case U_REQUEST_DATE:
            return QString("Request Date");
            break;
        }
    }
    else
        return QAbstractTableModel::headerData(section,orientation,role);
}

Qt::ItemFlags leavemodel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool leavemodel::leavemodel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(),row,row+count-1);
    for ( int i = 0 ; i < count ; i ++)
    {
        Leave *l = new Leave();
        QVector<int> employeeids;
        employeeids.append(employeeid);
        l->setLeaveDate(QDate::currentDate().addDays(1));
        l->setEndDate(QDate::currentDate().addDays(2));
        l->setPayType(1);
        l->setEmployeeIds(employeeids);
        l->setRequestDate(QDate::currentDate());
        QString error;
        if(!l->AddToStorage(error))
        {
            endInsertRows();
            return false;
        }

        leaves.insert(row+1+i,l);
    }
    endInsertRows();
    return true;
}

bool leavemodel::leavemodel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    if(row + count -1> leaves.count())
        return false;
    if(leaves.count()==0)
        return false;
    beginRemoveRows(QModelIndex(),row,row+count-1);
    for(int i = 0 ; i <count;i++)
    {
        Leave* l = leaves.at(row+i);
        try
        {
        l->deleteMe();
        }
        catch(QString s)
        {
            QMessageBox::warning(0,s,s);
        }

        leaves.removeAt(row+i);
        endRemoveRows();
    }
}

leavemodel::~leavemodel()
{
    QList<Leave*>::iterator i ;
    if(leaves.count()>0)
    {
        for (i=leaves.begin() ; i<leaves.end();i++)
        {
            delete (*i);
        }
    }
}

