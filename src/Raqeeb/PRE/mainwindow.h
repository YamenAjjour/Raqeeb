#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userhandlogdialog.h"
#include "../BLL/userhandler.h"
#include "addleave.h"
#include <QMap>
#include <QAction>
#include "adduser.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void showEvent(QShowEvent*event);
    void paintEvent(QPaintEvent *);
private slots:
    void on_actionOpen_2_triggered();
    void on_actionAdd_Leave_triggered();
    void on_actionAdd_bounce_triggered();
    void on_actionAdd_deduction_triggered();
    void on_actionNew_Month_triggered();

    void getEmployeeData(QModelIndex);
private:
    Ui::MainWindow *ui;
    UserHandler* userModel;
    addLeave* leave;
};

#endif // MAINWINDOW_H
