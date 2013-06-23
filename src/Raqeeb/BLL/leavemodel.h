#ifndef LEAVEMODEL_H
#define LEAVEMODEL_H

#include <QStandardItemModel>
#include "leave.h"
enum leavecolumn { U_ID ,U_REQUEST_DATE,U_LEAVE_DATE,U_PAY_TYPE};
class leavemodel : public QStandardItemModel
{
    Q_OBJECT
private:
    int size;
    int employeeid;
public:
    explicit leavemodel(QObject *parent = 0,int employeeid=-1);
    void init();
    bool addItem(Leave &l);
    bool removeItem(int id, QString &errorMessage);
    bool updateLeave(int id,Leave& l);
signals:
    
public slots:
    
};

#endif // LEAVEMODEL_H
