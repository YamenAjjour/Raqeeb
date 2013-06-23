#include "adduser.h"
#include "ui_adduser.h"
#include <QRegExp>
#include <QVariant>
AddUser::AddUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUser)
{
    ui->setupUi(this);
    connect(ui->pbtnAdd,SIGNAL(clicked()),this,SLOT(addUserSl()));
    connect(ui->pbtnCancel,SIGNAL(clicked()),this,SLOT(closeDialog()));
    QRegExp idExp("[0-9]{1,3}");
    QRegExp phoneExp("[0-9]{1,20}");
    QRegExp emailExp("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    QValidator* idValidator = new QRegExpValidator(idExp,this);
    QValidator* mobileValidator = new QRegExpValidator(phoneExp,this);
    QValidator* emailValidator = new QRegExpValidator(emailExp,this);
    ui->leID->setValidator(idValidator);
    ui->leMobile->setValidator(mobileValidator);
    ui->leEmail->setValidator(emailValidator);
    ui->lePhone->setValidator(mobileValidator);
    ui->leAnotherEmail->setValidator(emailValidator);
    ui->leHourPrice->setValidator(idValidator);
    hasData=false;
}

void AddUser::addUserSl()
{
    if(ui->leID->text().length()>0 && ui->leEmail->text().length()>0 && ui->leFirstName->text().length()>0 && ui->leSecondName->text().length()>0)
    {
        data.append(QVariant(ui->leID->text()));
        data.append(QVariant(ui->leFirstName->text()));
        data.append(QVariant(ui->leSecondName->text()));
        data.append(QVariant(ui->leEmail->text()));
        data.append(QVariant(ui->leAnotherEmail->text()));
        data.append(QVariant(ui->lePhone->text()));
        data.append(QVariant(ui->leMobile->text()));
        data.append(QVariant(ui->leHourPrice->text()));
        hasData=true;
        close();
    }

}

void  AddUser::closeDialog()
{
    hasData=false;
    close();
}

AddUser::~AddUser()
{
    delete ui;
}
bool AddUser::getData(QList<QVariant> &data)
{
    this->exec();
    if(hasData)
        data=this->data;
    return hasData;
}
