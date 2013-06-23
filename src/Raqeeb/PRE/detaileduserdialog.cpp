#include "detaileduserdialog.h"
#include "ui_detaileduserdialog.h"

detailedUserDialog::detailedUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailedUserDialog)
{
    ui->setupUi(this);
}

detailedUserDialog::~detailedUserDialog()
{
    delete ui;
}

void detailedUserDialog::setData(QString item ,int mode)
{

    if(mode==0)
    {
        ui->lgNightSh->insertItem(ui->lgNightSh->count(),item);
    }
    else
    {
        ui->lwForg->insertItem(ui->lwForg->count(),item);
    }
}
