#ifndef USERHANDLOGDIALOG_H
#define USERHANDLOGDIALOG_H

#include <QDialog>
#include "../BLL/userhandler.h"
namespace Ui {
    class UserHandlogDialog;
}

class UserHandlogDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserHandlogDialog(UserHandler*userModel,QWidget *parent = 0);
    ~UserHandlogDialog();

private:
    bool okToDelete(QDialog  *parent, const QString &title,
                    const QString &text, const QString &detailedText);
    Ui::UserHandlogDialog *ui;
    UserHandler * userModel;
private slots:
    bool addEmp();
    bool deleteEmp();
};

#endif // USERHANDLOGDIALOG_H
