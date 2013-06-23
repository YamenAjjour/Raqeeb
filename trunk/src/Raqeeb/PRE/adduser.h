#ifndef ADDUSER_H
#define ADDUSER_H

#include <QDialog>

namespace Ui {
    class AddUser;
}

class AddUser : public QDialog
{
    Q_OBJECT

public:
    explicit AddUser(QWidget *parent = 0);
    bool getData(QList<QVariant> &data);
    ~AddUser();
public slots:
    void addUserSl();
    void closeDialog();
private:
    Ui::AddUser *ui;
    QList<QVariant> data;
    bool hasData;
};

#endif // ADDUSER_H
