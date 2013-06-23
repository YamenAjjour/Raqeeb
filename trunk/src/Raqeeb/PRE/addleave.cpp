#include "addleave.h"
#include "ui_addleave.h"
#include "../BLL/leave.h"
#include <QPair>
#include <QList>
#include <QMessageBox>
#include "../DAL/userdal.h"
#include <QDebug>
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
    Leave* l = new Leave();
    QVector<int> empids;
    model->getCurrentIds(empids);
    l->setEmployeeIds(empids);
    l->setLeaveDate(ui->deLeaveDate->date());
    l->setEndDate(ui->deEndDate->date());
    l->setPayType(ui->cbxPayType->currentIndex());
    l->setRequestDate(QDate::currentDate());
    QString error;
    if(!l->AddToStorage(error))
       {
           QMessageBox::warning(this,error,error,QMessageBox::Ok);
           qDebug()<<error;
           return;
       }
    delete l ;
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
