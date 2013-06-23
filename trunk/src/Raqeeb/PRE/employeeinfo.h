#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include <QDialog>
#include "../BLL/leavemodel.h"
#include "../BLL/bouncemodel.h"
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
    bool getHasChanged();
    void initializeHeaders();
private slots:


    void on_pbtnUpdate_clicked();

    void on_pbtnAddLeave_clicked();

    void on_pbtnDelLeave_clicked();

    void on_pbtnAddBounce_clicked();

    void on_pbtnDeleteBounce_clicked();

    void on_pbtnAddRetribution_clicked();

    void on_pbtnDelRetribution_clicked();

private:
    Ui::EmployeeInfo *ui;
    int employeeid;
    leavemodel* lmodel;
    bool haschanged;
    bounceModel * bmodel;
    bounceModel * rmodel;
};

#endif // EMPLOYEEINFO_H
