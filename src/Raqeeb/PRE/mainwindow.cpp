#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../BLL/filehandler.h"
#include "../BLL/user.h"
#include <QList>
#include <QString>
#include "../BLL/userhandler.h"
#include <QFile>
#include <QShowEvent>
#include <QFileDialog>
#include <QApplication>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QCalendarWidget>
#include<QPair>
#include "detaileduserdialog.h"
#include "adduser.h"
#include "addbounce.h"
#include "../BLL/bounce.h"
#include "newsalary.h"
#include "employeeinfo.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tvEmployees->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->tvEmployees,SIGNAL(clicked(QModelIndex)),this,SLOT(getEmployeeData(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent*event)
{

    userModel= new UserHandler(this);
    QString s;
    userModel->init(s);
    this->ui->tvEmployees->setModel(userModel);
    this->ui->tvEmployees->setColumnWidth(0,this->width()/6);
    this->ui->tvEmployees->setColumnWidth(1,this->width()/6);
    this->ui->tvEmployees->setColumnWidth(2,this->width()/6);
    this->ui->tvEmployees->setColumnWidth(3,this->width()/6);
    this->ui->tvEmployees->setColumnWidth(4,this->width()/6);
    this->ui->tvEmployees->setColumnWidth(5,this->width()/6);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    this->ui->tvEmployees->setModel(userModel);
    this->ui->tvEmployees->setColumnWidth(0,this->width()/6);
    this->ui->tvEmployees->setColumnWidth(1,this->width()/6);
    this->ui->tvEmployees->setColumnWidth(2,this->width()/6);
    this->ui->tvEmployees->setColumnWidth(3,this->width()/6);
    this->ui->tvEmployees->setColumnWidth(4,this->width()/6);
    this->ui->tvEmployees->setColumnWidth(5,this->width()/6);
}

void MainWindow::on_actionOpen_2_triggered()
{
    QString error;
    AddUser* addUserDia = new AddUser();
    QList<QVariant> data;
    if(addUserDia->getData(data))
    {
        int id=data.at(0).toInt();
        QString firstName = data.at(1).toString();
        QString lastName = data.at(2).toString();
        QString email = data.at(3).toString();
        QString phone =data.at(4).toString();
        QString anotherEmail =data.at(5).toString();
        QString mobile =data.at(6).toString();
        double hourPrice =data.at(7).toDouble();
        User u(id,firstName,lastName,email,phone,anotherEmail,mobile,hourPrice);
        u.addToStorage();
        userModel->init(error);
    }
}

void MainWindow::on_actionAdd_Leave_triggered()
{
    leave = new addLeave(this);
    leave->exec();

}

void MainWindow::on_actionAdd_bounce_triggered()
{
    addbounce* addb = new addbounce(this);
    QPair<int,int> data;
    if(addb->getData(data))
    {
        QString error;
        bounce b;
        b.setAddDate(QDate::currentDate());
        b.setAmount(data.second);
        b.setEmpId(data.first);
        b.setDone(0);
        b.setType(0);
        if(!b.addToStorage(error))
            QMessageBox::warning(0,error,error,QMessageBox::Ok);
    }
}

void MainWindow::on_actionAdd_deduction_triggered()
{
    addbounce* addb = new addbounce(this);
    QPair<int,int> data;
    if(addb->getData(data))
    {
        QString error;
        bounce b;
        b.setAddDate(QDate::currentDate());
        b.setAmount(data.second);
        b.setEmpId(data.first);
        b.setDone(0);
        b.setType(1);
        if(!b.addToStorage(error))
            QMessageBox::warning(0,error,error,QMessageBox::Ok);
    }
}

void MainWindow::on_actionNew_Month_triggered()
{
    NewSalary *neSalary = new NewSalary(this);
    neSalary->exec();
}

void MainWindow::getEmployeeData(QModelIndex i)
{
    EmployeeInfo* e = new EmployeeInfo(this,userModel->item(i.row(),U_ID)->text().toInt());
    e->show();
}
