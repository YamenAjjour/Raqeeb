#ifndef ADDLEAVE_H
#define ADDLEAVE_H

#include <QDialog>
#include "addleaveemp.h"
#include "../BLL/empidmodel.h"
namespace Ui {
    class addLeave;
}

class addLeave : public QDialog
{
    Q_OBJECT

public:
    explicit addLeave(QWidget *parent = 0);
    ~addLeave();

private slots:
    void on_pbtnAdd_clicked();

    void on_pbtnAddEmp_clicked();

    void on_pbtnRemEmp_clicked();

    void on_pbtnSelectAll_clicked();

private:
    Ui::addLeave *ui;
    addLeaveEmp* emp;
    empidModel * model;
};

#endif // ADDLEAVE_H
