#ifndef NewSalary_H
#define NewSalary_H

#include <QDialog>
#include "userhandlogdialog.h"
#include "../BLL/userhandler.h"
#include <QMap>
namespace Ui {
    class NewSalary;
}

class NewSalary : public QDialog
{
    Q_OBJECT

public:
    explicit NewSalary(QWidget *parent = 0);
    ~NewSalary();
protected:
    void showEvent(QShowEvent*event);
private:
    Ui::NewSalary *ui;
    UserHandler* userModel;
    QString fileName;
    QMap<int,QList<QPair<Log,Log> > > nightShiftData;
    QMap<int,QList<Log> > forgData;
private slots:
    void openFileDialog();
    void displayData();
    void dateChanged();
    void showDetailedUserDialog(const QModelIndex &index);
};

#endif // NewSalary_H
