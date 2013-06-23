#ifndef ADDLEAVEEMP_H
#define ADDLEAVEEMP_H

#include <QDialog>
#include "../BLL/user.h"

namespace Ui {
    class addLeaveEmp;
}

class addLeaveEmp : public QDialog
{
    Q_OBJECT

public:
    explicit addLeaveEmp(QWidget *parent = 0);
    ~addLeaveEmp();
    bool getEmployee(QPair<QString,int> &data);

private slots:
    void on_pbtnAddEmp_clicked();
    void on_cbxEmpName_editTextChanged(const QString &arg1);
    void AddEmp();
private:
    Ui::addLeaveEmp *ui;
    QList<User> users;
    bool hasData;
};

#endif // ADDLEAVEEMP_H
