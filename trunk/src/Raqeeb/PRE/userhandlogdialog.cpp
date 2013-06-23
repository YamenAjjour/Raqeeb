#include "userhandlogdialog.h"
#include "ui_userhandlogdialog.h"
#include <QStandardItem>
#include <QList>
#include <QItemSelectionModel>
#include <QMessageBox>
UserHandlogDialog::UserHandlogDialog(UserHandler* userModel,QWidget *parent) :
        QDialog(parent),
        ui(new Ui::UserHandlogDialog)
{
    this->userModel=userModel;
    ui->setupUi(this);
    this->userModel=userModel;
    ui->tw_usersInfo->setModel(userModel);
    ui->tw_usersInfo->setColumnWidth(0,100);
    ui->tw_usersInfo->setColumnWidth(1,300);
    ui->tw_usersInfo->setColumnWidth(2,150);
    connect(ui->pbtnAddEmployee,SIGNAL(clicked()),this,SLOT(addEmp()));
    connect(ui->pbtnDelEmp,SIGNAL(clicked()),this,SLOT(deleteEmp()));
}

UserHandlogDialog::~UserHandlogDialog()
{
    delete ui;
}

bool UserHandlogDialog::addEmp()
{
    if(userModel)
    {
        QList<QStandardItem*> items;
        for(int i=0;i<userModel->columnCount();i++)
            items<<new QStandardItem(tr("UnKnown"));
        userModel->appendRow(items);
        ui->tw_usersInfo->scrollToBottom();
        ui->tw_usersInfo->setFocus();
        QModelIndex index = userModel->index(userModel->rowCount()-1,E_ID);
        ui->tw_usersInfo->setCurrentIndex(index);
        ui->tw_usersInfo->edit(index);
        return true;
    }
    else return false;

}
bool UserHandlogDialog::okToDelete(QDialog *parent, const QString &title,
                const QString &text, const QString &detailedText)
{
    QScopedPointer<QMessageBox> messageBox(new QMessageBox(parent));
    if (parent)
        messageBox->setWindowModality(Qt::WindowModal);
    messageBox->setIcon(QMessageBox::Question);
    messageBox->setWindowTitle(QString("%1 - %2")
            .arg(QApplication::applicationName()).arg(title));
    messageBox->setText(text);
    if (!detailedText.isEmpty())
        messageBox->setInformativeText(detailedText);
    QAbstractButton *deleteButton = messageBox->addButton(
            QObject::tr("&Delete"), QMessageBox::AcceptRole);
    messageBox->addButton(QObject::tr("Do &Not Delete"),
                          QMessageBox::RejectRole);
    messageBox->setDefaultButton(
            qobject_cast<QPushButton*>(deleteButton));
    messageBox->exec();
    return messageBox->clickedButton() == deleteButton;
}

bool UserHandlogDialog::deleteEmp()
{
    if(userModel)
    {
        QItemSelectionModel* selectionModel = ui->tw_usersInfo->selectionModel();
        if(!selectionModel->hasSelection())
            return false;
        QModelIndex index = selectionModel->currentIndex();
        if(!index.isValid())
            return false;
        QString name = userModel->data(userModel->index(index.row(),E_NAME)).toString();
        if(!okToDelete(this,tr("Delete Employee"),tr("do you want really to delete %1").arg(name),""))
            return false;
        else
        {
            userModel->removeRow(index.row(),index.parent());
            return true;
        }
    }
    else
        return false;
}

