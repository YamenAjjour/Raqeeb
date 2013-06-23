#include "addleave.h"
#include "ui_addleave.h"
#include "../BLL/leave.h"
#include <QPair>
#include <QList>
#include <QMessageBox>
#include "../DAL/userdal.h"
addLeave::addLeave(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addLeave)
{
    ui->setupUi(this);
    model= new empidModel(this);
    ui->lvEmployee->setModel(model);
}

addLeave::~addLeave()
{
    delete ui;
}

void addLeave::on_pbtnAdd_clicked()
{
    QList<int> empIds;
    model->getCurrentIds(empIds);
    Leave* l = new Leave();
    l->setLeaveDate(ui->deLeaveDate->date());
    l->setPayType(ui->cbxPayType->currentIndex());
    l->setRequestDate(QDate::currentDate());
    QString error;
    for(int i =0;i<empIds.size();i++)
    {
        l->setEmployeeId(empIds[i]);
       if(!l->AddToStorage(error))
       {
           QMessageBox::warning(this,error,error,QMessageBox::Ok);
           return;
       }
    }
    close();
}

void addLeave::on_pbtnAddEmp_clicked()
{
    emp = new addLeaveEmp(this);
    QPair<QString,int> data;
    if(emp->getEmployee(data))
    {
        model->AddItem(data.first,data.second);
    }
}

void addLeave::on_pbtnRemEmp_clicked()
{
    model->RemoveItem(ui->lvEmployee->selectionModel()->currentIndex());

}

void addLeave::on_pbtnSelectAll_clicked()
{
    model->fill();
}
