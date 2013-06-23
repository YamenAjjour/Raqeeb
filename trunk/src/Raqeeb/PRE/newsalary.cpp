#include "newsalary.h"
#include "ui_newsalary.h"
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
NewSalary::NewSalary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewSalary)
{
    ui->setupUi(this);
    connect(ui->dFromDate,SIGNAL(dateChanged(QDate)),this,SLOT(dateChanged()));
    connect(ui->dToDate,SIGNAL(dateChanged(QDate)),this,SLOT(dateChanged()));
    connect(ui->tableWidget,SIGNAL(clicked(QModelIndex)),this,SLOT(showDetailedUserDialog(QModelIndex)));
    ui->tableWidget->setColumnCount(4);
    QStringList headers;
    headers.append(tr("ID"));
    headers.append(tr("Name"));
    headers.append(tr("Number of Hours"));
    headers.append(tr("Salary"));
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

NewSalary::~NewSalary()
{
    delete ui;
}

void NewSalary::showEvent(QShowEvent*event)
{
    userModel= new UserHandler(this);
    QString error;
    if(!userModel->init(error))
        QMessageBox::warning(this,error,error,QMessageBox::Ok);
    openFileDialog();
}


void NewSalary::openFileDialog()
{

    fileName = QFileDialog::getOpenFileName(this,tr("Open File"),QApplication::applicationDirPath());
    if(fileName.length()==0)
        return;
    if(fileName.right(3)=="dat")
        displayData();
    else
        QMessageBox::warning(this,tr("invalid file format !"),tr("please enter a file whose extension is dat !"),QMessageBox::Ok);
}

void NewSalary::displayData()
{
    forgData.clear();
    nightShiftData.clear();
    ui->tableWidget->clear();
    QList<User> users;
    try
    {
        FileHandler parser(fileName);
        parser.getUsers(users);
    }catch ( char* Message)
    {
        QMessageBox::warning(this,"error",Message,QMessageBox::Ok);
    }
    catch ( QString Message)
    {
        QMessageBox::warning(this,"error",Message,QMessageBox::Ok);
    }

    int x;
    QList<Log> fogToSig;
    QList<QPair<Log,Log> > nightShift;
    int counter=0;
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(users.count());
    QStringList headers;
    headers.append(tr("ID"));
    headers.append(tr("Name"));
    headers.append(tr("Number of Hours"));
    headers.append(tr("Salary"));
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    foreach(User u , users)
    {
        fogToSig.clear();
        nightShift.clear();
        ui->tableWidget->insertRow(counter);
        QPair<QString,double> info;
        if(userModel->getUserInfo(u.getMachineId(),info))
        {
            int hour = u.calcHour(ui->dFromDate->date(),ui->dToDate->date(),fogToSig,nightShift);
            forgData[u.getMachineId()]=fogToSig;
            nightShiftData[u.getMachineId()]=nightShift;
            QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(u.getMachineId()));
            QTableWidgetItem* nameItem = new QTableWidgetItem(info.first);
            QTableWidgetItem* numOfhourItem = new QTableWidgetItem(QString::number(hour));
            QTableWidgetItem* salaryItem = new QTableWidgetItem(QString::number(info.second*hour));
            idItem->setTextAlignment(Qt::AlignCenter);
            nameItem->setTextAlignment(Qt::AlignCenter);
            numOfhourItem->setTextAlignment(Qt::AlignCenter);
            salaryItem->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(counter,0,idItem);
            ui->tableWidget->setItem(counter,1,nameItem);
            ui->tableWidget->setItem(counter,2,numOfhourItem);
            ui->tableWidget->setItem(counter,3,salaryItem);
            counter++;
        }
    }
    ui->tableWidget->setRowCount(counter);
}

void NewSalary::dateChanged()
{
    if(fileName.length()>0)
        displayData();
}

void NewSalary::showDetailedUserDialog(const QModelIndex &index)
{
    int x = index.row();
    int y = ui->tableWidget->rowCount();
    if(index.isValid())
    {
        QList<QPair<Log,Log> > nighShiftTemp;
        QList<Log> forgTemp;
        detailedUserDialog* d= new detailedUserDialog();
        int id =ui->tableWidget->item(index.row(),E_ID)->data(Qt::DisplayRole).toInt();
        if(forgData.contains(id))
        {
            nighShiftTemp=nightShiftData[id];
            forgTemp=forgData[id];
        }
        else
            return;
        for(int i=0;i<nighShiftTemp.count();i++)
        {
            QString str;
            str.append("from  ");
            str.append(QString::number(nighShiftTemp.at(i).first.getDate().day()));
            str.append(" at "+nighShiftTemp.at(i).first.getTime().toString());
            str.append("  to ");
            str.append(QString::number(nighShiftTemp.at(i).second.getDate().day()));
            str.append(" at "+nighShiftTemp.at(i).second.getTime().toString());
            d->setData(str,0);
        }
        for(int i=0;i<forgTemp.count();i++)
        {
            QString str;
            str.append(forgTemp[i].getDate().toString("yyyy-MM-dd")+" at "+forgTemp[i].getTime().toString());
            d->setData(str,1);
        }
        d->exec();
        delete d;
    }
}
