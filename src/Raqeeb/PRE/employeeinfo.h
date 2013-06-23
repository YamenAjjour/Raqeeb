#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include <QDialog>
#include "../BLL/leavemodel.h"
namespace Ui {
    class EmployeeInfo;
}

class EmployeeInfo : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeInfo(QWidget *parent = 0, int id=-1);
    ~EmployeeInfo();
    void setEmployeeId(int id );
    int getEmployeeId();
    void setData();
private:
    Ui::EmployeeInfo *ui;
    int employeeid;
    leavemodel* lmodel;
};

#endif // EMPLOYEEINFO_H
