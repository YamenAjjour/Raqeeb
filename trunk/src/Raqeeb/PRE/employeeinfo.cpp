#include "employeeinfo.h"
#include "ui_employeeinfo.h"
#include <QList>
#include "../BLL/user.h"
#include "../BLL/bounce.h"
#include <QMessageBox>
EmployeeInfo::EmployeeInfo(QWidget *parent,int id) :
    QDialog(parent),
    ui(new Ui::EmployeeInfo)
{
    ui->setupUi(this);
    lmodel = new leavemodel(this,id);
    bmodel = new bounceModel(0,id,this);
    rmodel = new bounceModel(1,id,this);
    ui->tvLeaves->setModel(lmodel);
    ui->tvBounce->setModel(bmodel);
    ui->tvRetribution->setModel(rmodel);
    this->employeeid=id;
    User u ;
    u.getUserById(id,u);
    ui->leMachineId->setText(QString::number(u.getMachineId()));
    ui->leFirstName->setText(u.getFirstName());
    ui->leLastName->setText(u.getLastName());
    ui->leHourPrice->setText(QString::number(u.getHourPrice()));
    ui->leMobile->setText(u.getMobile());
    ui->lePhone->setText(u.getPhone());
    ui->leEmail->setText(u.getEmail());
    haschanged=false;
}

EmployeeInfo::~EmployeeInfo()
{
    delete ui;
}

void EmployeeInfo::setEmployeeId(int id)
{
    this->employeeid=id;
}

int EmployeeInfo::getEmployeeId()
{
    return employeeid;
}

void EmployeeInfo::setData()
{

}

bool EmployeeInfo::getHasChanged()
{
    return haschanged;
}

void EmployeeInfo::initializeHeaders()
{
    QStringList headers;
    headers.append(tr("ID"));
    headers.append(tr("Name"));
    headers.append(tr("Number of Hours"));
    headers.append(tr("Salary"));
}

void EmployeeInfo::on_pbtnUpdate_clicked()
{
    User u;
    u.setId(employeeid);
    u.setFirstName(ui->leFirstName->text());
    u.setLastName(ui->leLastName->text());
    u.setEmail(ui->leEmail->text());
    u.setHourPrice(ui->leHourPrice->text().toDouble());
    u.setMobile(ui->leMobile->text());
    u.setPhone(ui->lePhone->text());
    u.setMachineId(ui->leMachineId->text().toInt());
    u.update();
    haschanged=true;
    close();
}

void EmployeeInfo::on_pbtnAddLeave_clicked()
{
    if(!lmodel->insertRow(lmodel->rowCount(QModelIndex())))
        QMessageBox::warning(0,"Cannot add row ! " , "Cannot add row !");
    QModelIndex index = lmodel->index(lmodel->rowCount(QModelIndex()),0);
    ui->tvLeaves->setCurrentIndex(index);
    ui->tvLeaves->scrollToBottom();
    ui->tvLeaves->setFocus();
    ui->tvLeaves->edit(index);
}

void EmployeeInfo::on_pbtnDelLeave_clicked()
{
    if(ui->tvLeaves->selectionModel()->currentIndex().isValid())
        lmodel->removeRow(ui->tvLeaves->selectionModel()->currentIndex().row(),QModelIndex());
    else
        QMessageBox::warning(0,tr("Warning !"),tr("please select a leave and then  click delete ! "));
}

void EmployeeInfo::on_pbtnAddBounce_clicked()
{
}

void EmployeeInfo::on_pbtnDeleteBounce_clicked()
{

}

void EmployeeInfo::on_pbtnAddRetribution_clicked()
{

}

void EmployeeInfo::on_pbtnDelRetribution_clicked()
{

}
