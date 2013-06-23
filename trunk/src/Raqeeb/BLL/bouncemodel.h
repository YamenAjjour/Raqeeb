#ifndef BOUNCEMODEL_H
#define BOUNCEMODEL_H

#include <QStandardItemModel>
#include "../BLL/bounce.h"
#include <QList>
enum bounceCol {U_AMOUNT,U_ADDDATE,U_PAYDATE,U_DONE};
class bounceModel : public QStandardItemModel
{
    Q_OBJECT
private:
    int type ;
    int empid ;
    void prepareBounce(bounce * b , QList<QStandardItem*>& items);
    void forceDataChange();
public:
    explicit bounceModel(int type, int empid ,QObject *parent = 0);
    void initialize(int type, int empid);
    void finalize () ;
    void setType( int type );
    void setEmpid(int empid);
    int geType();
    int getEmpid();
    bool addBounce(bounce * b);
    bool removeBounce(bounce * b, int row);
    
signals:
    
public slots:
    
};

#endif // BOUNCEMODEL_H
