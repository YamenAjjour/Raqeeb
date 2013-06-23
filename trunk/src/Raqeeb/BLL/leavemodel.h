#ifndef LEAVEMODEL_H
#define LEAVEMODEL_H

#include <QAbstractTableModel>
#include "leave.h"
#include <QtCore>
enum leavecolumn { U_LEAVE_DATE,U_END_DATE,U_PAY_TYPE,U_REQUEST_DATE};
class leavemodel : public QAbstractTableModel
{
    Q_OBJECT
private:
    int size;
    int employeeid;
    QList<Leave*> leaves;
public:
    explicit leavemodel(QObject *parent = 0,int employeeid=-1);
    void init();
    bool updateLeave(int id,Leave& l);
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant data(const QModelIndex &index, int role) const;
    int columnCount(const QModelIndex &parent) const;
    int rowCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool  insertRows(int row, int count, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    ~leavemodel();
signals:
    
public slots:
    
};

#endif // LEAVEMODEL_H
