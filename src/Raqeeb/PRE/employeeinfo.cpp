#include "employeeinfo.h"
#include "ui_employeeinfo.h"
#include <QList>
#include "../BLL/User.h"
EmployeeInfo::EmployeeInfo(QWidget *parent,int id) :
    QDialog(parent),
    ui(new Ui::EmployeeInfo)
{
    ui->setupUi(this);
    lmodel = new leavemodel(this);
    lmodel->init();
    ui->tvLeaves->setModel(lmodel);
    this->employeeid=id;


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
