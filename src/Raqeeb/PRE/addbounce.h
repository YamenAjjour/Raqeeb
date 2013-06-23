#ifndef ADDBOUNCE_H
#define ADDBOUNCE_H

#include <QDialog>
#include <QPair>
#include <QList>
#include "../BLL/user.h"
namespace Ui {
    class addbounce;
}

class addbounce : public QDialog
{
    Q_OBJECT

public:
    explicit addbounce(QWidget *parent = 0);
    ~addbounce();
    bool getData(QPair <int ,int> & data);

private slots:
    void on_pbtnAdd_clicked();
    void on_ptbtnAdd_clicked();

private:
    Ui::addbounce *ui;
    bool hasData;
    QList<User> users;
};

#endif // ADDBOUNCE_H
