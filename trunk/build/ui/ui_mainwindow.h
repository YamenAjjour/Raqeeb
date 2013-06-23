/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Sep 1 02:50:07 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionExit_2;
    QAction *actionOppen;
    QAction *actionSaveReport;
    QAction *actionClose;
    QAction *actionManage;
    QAction *actionAdd_User;
    QAction *AddEmployee;
    QAction *actionAdd_Leave;
    QAction *actionAdd_bounce;
    QAction *actionAdd_deduction;
    QAction *actionMonth_Payroll;
    QAction *actionEmployee_salary;
    QAction *actionNew_Month;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tvEmployees;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuReport;
    QMenu *menuNew_Month;
    QMenu *menuTools;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(597, 498);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit_2 = new QAction(MainWindow);
        actionExit_2->setObjectName(QString::fromUtf8("actionExit_2"));
        actionOppen = new QAction(MainWindow);
        actionOppen->setObjectName(QString::fromUtf8("actionOppen"));
        actionSaveReport = new QAction(MainWindow);
        actionSaveReport->setObjectName(QString::fromUtf8("actionSaveReport"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionManage = new QAction(MainWindow);
        actionManage->setObjectName(QString::fromUtf8("actionManage"));
        actionAdd_User = new QAction(MainWindow);
        actionAdd_User->setObjectName(QString::fromUtf8("actionAdd_User"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/addemployee.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_User->setIcon(icon);
        AddEmployee = new QAction(MainWindow);
        AddEmployee->setObjectName(QString::fromUtf8("AddEmployee"));
        AddEmployee->setIcon(icon);
        actionAdd_Leave = new QAction(MainWindow);
        actionAdd_Leave->setObjectName(QString::fromUtf8("actionAdd_Leave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/addleave.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Leave->setIcon(icon1);
        actionAdd_bounce = new QAction(MainWindow);
        actionAdd_bounce->setObjectName(QString::fromUtf8("actionAdd_bounce"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/addbonus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_bounce->setIcon(icon2);
        actionAdd_deduction = new QAction(MainWindow);
        actionAdd_deduction->setObjectName(QString::fromUtf8("actionAdd_deduction"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/addreduction.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_deduction->setIcon(icon3);
        actionMonth_Payroll = new QAction(MainWindow);
        actionMonth_Payroll->setObjectName(QString::fromUtf8("actionMonth_Payroll"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/monthpayrollreport.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionMonth_Payroll->setIcon(icon4);
        actionEmployee_salary = new QAction(MainWindow);
        actionEmployee_salary->setObjectName(QString::fromUtf8("actionEmployee_salary"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/employeereport.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionEmployee_salary->setIcon(icon5);
        actionNew_Month = new QAction(MainWindow);
        actionNew_Month->setObjectName(QString::fromUtf8("actionNew_Month"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/icons/newmonth.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Month->setIcon(icon6);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tvEmployees = new QTableView(centralWidget);
        tvEmployees->setObjectName(QString::fromUtf8("tvEmployees"));

        verticalLayout->addWidget(tvEmployees);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 597, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuReport = new QMenu(menuBar);
        menuReport->setObjectName(QString::fromUtf8("menuReport"));
        menuNew_Month = new QMenu(menuBar);
        menuNew_Month->setObjectName(QString::fromUtf8("menuNew_Month"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuReport->menuAction());
        menuBar->addAction(menuNew_Month->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuFile->addAction(AddEmployee);
        menuFile->addAction(actionAdd_Leave);
        menuFile->addAction(actionAdd_bounce);
        menuFile->addAction(actionAdd_deduction);
        menuReport->addAction(actionMonth_Payroll);
        menuReport->addAction(actionEmployee_salary);
        menuNew_Month->addAction(actionNew_Month);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Raqeeb", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionExit_2->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionOppen->setText(QApplication::translate("MainWindow", "open", 0, QApplication::UnicodeUTF8));
        actionSaveReport->setText(QApplication::translate("MainWindow", "Save Report", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionManage->setText(QApplication::translate("MainWindow", "Manage", 0, QApplication::UnicodeUTF8));
        actionAdd_User->setText(QApplication::translate("MainWindow", "Add User", 0, QApplication::UnicodeUTF8));
        AddEmployee->setText(QApplication::translate("MainWindow", "Add Employee", 0, QApplication::UnicodeUTF8));
        actionAdd_Leave->setText(QApplication::translate("MainWindow", "Add Leave", 0, QApplication::UnicodeUTF8));
        actionAdd_bounce->setText(QApplication::translate("MainWindow", "Add bounce", 0, QApplication::UnicodeUTF8));
        actionAdd_deduction->setText(QApplication::translate("MainWindow", "Add deduction", 0, QApplication::UnicodeUTF8));
        actionMonth_Payroll->setText(QApplication::translate("MainWindow", "Month Payroll", 0, QApplication::UnicodeUTF8));
        actionEmployee_salary->setText(QApplication::translate("MainWindow", "Employee salary", 0, QApplication::UnicodeUTF8));
        actionNew_Month->setText(QApplication::translate("MainWindow", "New Month", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "HR", 0, QApplication::UnicodeUTF8));
        menuReport->setTitle(QApplication::translate("MainWindow", "Report", 0, QApplication::UnicodeUTF8));
        menuNew_Month->setTitle(QApplication::translate("MainWindow", "Payroll", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "Configuration", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
