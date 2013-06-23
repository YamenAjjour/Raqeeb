#include "addleaveemp.h"
#include "ui_addleaveemp.h"
#include "../BLL/user.h"
#include "../DAL/userDAL.h"
#include <QList>
#include <QPair>
addLeaveEmp::addLeaveEmp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addLeaveEmp)
{
    hasData=false;
    ui->setupUi(this);
    connect(ui->pbtnAddEmp,SIGNAL(clicked()),this,SLOT(AddEmp()));
    UserDal::getAllUser(users);
    for(int i=0;i<users.count();i++)
    {
        ui->cbxEmpName->addItem(users[i].getFirstName(),users[i].getId());
    }
}

addLeaveEmp::~addLeaveEmp()
{
    delete ui;
}




void addLeaveEmp::on_pbtnAddEmp_clicked()
{

}

void addLeaveEmp::on_cbxEmpName_editTextChanged(const QString &arg1)
{

}

 bool addLeaveEmp::getEmployee(QPair<QString,int> &data)
{
    exec();
    if(hasData)
    {
        data.first=ui->cbxEmpName->currentText();
        data.second=ui->cbxEmpName->itemData(ui->cbxEmpName->currentIndex()).toInt();
        return true;
    }
    return false;
}
void addLeaveEmp::AddEmp()
{
    hasData=true;
    close();
}
