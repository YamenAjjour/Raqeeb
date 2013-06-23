#include "addbounce.h"
#include "ui_addbounce.h"
#include "../DAL/userdal.h"
addbounce::addbounce(int type , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addbounce)
{
    ui->setupUi(this);
    QRegExp idExp("[0-9]{1,5}");
    QValidator* idValidator = new QRegExpValidator(idExp,this);
    ui->leAmount->setValidator(idValidator);
    hasData=false;
    UserDal::getAllUser(users);
    for(int i=0;i<users.count();i++)
    {
        ui->cbxEmployee->addItem(users[i].getFirstName(),users[i].getId());
    }
    setType(type);
}

addbounce::~addbounce()
{
    delete ui;
}

void addbounce::on_pbtnAdd_clicked()
{
    hasData=true;
    close();
}

void addbounce::on_ptbtnAdd_clicked()
{
    close();
}

bool addbounce::getData(QPair<int, int> &data)
{
    exec();
    if(hasData)
    {
        data.first=ui->cbxEmployee->itemData(ui->cbxEmployee->currentIndex()).toInt();
        data.second=ui->leAmount->text().toInt();
        return true;
    }
    return false;
}

int addbounce::getType()
{
    return type;
}


void addbounce::setType(int type)
{
    this->type = type;
}
