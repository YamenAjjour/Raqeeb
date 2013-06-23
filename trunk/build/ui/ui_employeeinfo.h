/********************************************************************************
** Form generated from reading UI file 'employeeinfo.ui'
**
** Created: Sat Sep 8 04:30:05 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEINFO_H
#define UI_EMPLOYEEINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeInfo
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *personal;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *leMachineId;
    QLabel *label_5;
    QLineEdit *lePhone;
    QLabel *label_2;
    QLineEdit *leFirstName;
    QLabel *label_6;
    QLineEdit *leAnotherEmail;
    QLabel *label_3;
    QLineEdit *leLastName;
    QLabel *label_7;
    QLineEdit *leMobile;
    QLabel *label_4;
    QLineEdit *leEmail;
    QLabel *label_8;
    QLineEdit *leHourPrice;
    QWidget *leaves;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QTableView *tvLeaves;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pbtnAddLeave;
    QPushButton *pbtnDelLeave;
    QSpacerItem *verticalSpacer;
    QWidget *retribution;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QTableView *tvRetribution;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pbtnAddRetribution;
    QPushButton *pbtnDelRetribution;
    QSpacerItem *verticalSpacer_2;
    QWidget *bounces;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tvBounce;
    QVBoxLayout *verticalLayout_8;
    QPushButton *pbtnAddBounce;
    QPushButton *pbtnDeleteBounce;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbtnClose;
    QPushButton *pbtnUpdate;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *EmployeeInfo)
    {
        if (EmployeeInfo->objectName().isEmpty())
            EmployeeInfo->setObjectName(QString::fromUtf8("EmployeeInfo"));
        EmployeeInfo->resize(563, 310);
        verticalLayout_6 = new QVBoxLayout(EmployeeInfo);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tabWidget = new QTabWidget(EmployeeInfo);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        personal = new QWidget();
        personal->setObjectName(QString::fromUtf8("personal"));
        verticalLayout = new QVBoxLayout(personal);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(22);
        gridLayout->setVerticalSpacing(32);
        label = new QLabel(personal);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leMachineId = new QLineEdit(personal);
        leMachineId->setObjectName(QString::fromUtf8("leMachineId"));

        gridLayout->addWidget(leMachineId, 0, 1, 1, 1);

        label_5 = new QLabel(personal);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        lePhone = new QLineEdit(personal);
        lePhone->setObjectName(QString::fromUtf8("lePhone"));

        gridLayout->addWidget(lePhone, 0, 3, 1, 1);

        label_2 = new QLabel(personal);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leFirstName = new QLineEdit(personal);
        leFirstName->setObjectName(QString::fromUtf8("leFirstName"));

        gridLayout->addWidget(leFirstName, 1, 1, 1, 1);

        label_6 = new QLabel(personal);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        leAnotherEmail = new QLineEdit(personal);
        leAnotherEmail->setObjectName(QString::fromUtf8("leAnotherEmail"));

        gridLayout->addWidget(leAnotherEmail, 1, 3, 1, 1);

        label_3 = new QLabel(personal);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leLastName = new QLineEdit(personal);
        leLastName->setObjectName(QString::fromUtf8("leLastName"));

        gridLayout->addWidget(leLastName, 2, 1, 1, 1);

        label_7 = new QLabel(personal);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 2, 1, 1);

        leMobile = new QLineEdit(personal);
        leMobile->setObjectName(QString::fromUtf8("leMobile"));

        gridLayout->addWidget(leMobile, 2, 3, 1, 1);

        label_4 = new QLabel(personal);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leEmail = new QLineEdit(personal);
        leEmail->setObjectName(QString::fromUtf8("leEmail"));

        gridLayout->addWidget(leEmail, 3, 1, 1, 1);

        label_8 = new QLabel(personal);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 2, 1, 1);

        leHourPrice = new QLineEdit(personal);
        leHourPrice->setObjectName(QString::fromUtf8("leHourPrice"));

        gridLayout->addWidget(leHourPrice, 3, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        tabWidget->addTab(personal, QString());
        leaves = new QWidget();
        leaves->setObjectName(QString::fromUtf8("leaves"));
        verticalLayout_7 = new QVBoxLayout(leaves);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tvLeaves = new QTableView(leaves);
        tvLeaves->setObjectName(QString::fromUtf8("tvLeaves"));

        horizontalLayout->addWidget(tvLeaves);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pbtnAddLeave = new QPushButton(leaves);
        pbtnAddLeave->setObjectName(QString::fromUtf8("pbtnAddLeave"));

        verticalLayout_2->addWidget(pbtnAddLeave);

        pbtnDelLeave = new QPushButton(leaves);
        pbtnDelLeave->setObjectName(QString::fromUtf8("pbtnDelLeave"));

        verticalLayout_2->addWidget(pbtnDelLeave);

        verticalSpacer = new QSpacerItem(20, 108, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_7->addLayout(horizontalLayout);

        tabWidget->addTab(leaves, QString());
        retribution = new QWidget();
        retribution->setObjectName(QString::fromUtf8("retribution"));
        verticalLayout_4 = new QVBoxLayout(retribution);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        tvRetribution = new QTableView(retribution);
        tvRetribution->setObjectName(QString::fromUtf8("tvRetribution"));

        horizontalLayout_4->addWidget(tvRetribution);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pbtnAddRetribution = new QPushButton(retribution);
        pbtnAddRetribution->setObjectName(QString::fromUtf8("pbtnAddRetribution"));

        verticalLayout_3->addWidget(pbtnAddRetribution);

        pbtnDelRetribution = new QPushButton(retribution);
        pbtnDelRetribution->setObjectName(QString::fromUtf8("pbtnDelRetribution"));

        verticalLayout_3->addWidget(pbtnDelRetribution);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_4);

        tabWidget->addTab(retribution, QString());
        bounces = new QWidget();
        bounces->setObjectName(QString::fromUtf8("bounces"));
        verticalLayout_9 = new QVBoxLayout(bounces);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tvBounce = new QTableView(bounces);
        tvBounce->setObjectName(QString::fromUtf8("tvBounce"));

        horizontalLayout_2->addWidget(tvBounce);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        pbtnAddBounce = new QPushButton(bounces);
        pbtnAddBounce->setObjectName(QString::fromUtf8("pbtnAddBounce"));

        verticalLayout_8->addWidget(pbtnAddBounce);

        pbtnDeleteBounce = new QPushButton(bounces);
        pbtnDeleteBounce->setObjectName(QString::fromUtf8("pbtnDeleteBounce"));

        verticalLayout_8->addWidget(pbtnDeleteBounce);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_8);


        verticalLayout_9->addLayout(horizontalLayout_2);

        tabWidget->addTab(bounces, QString());

        verticalLayout_5->addWidget(tabWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pbtnClose = new QPushButton(EmployeeInfo);
        pbtnClose->setObjectName(QString::fromUtf8("pbtnClose"));

        horizontalLayout_3->addWidget(pbtnClose);

        pbtnUpdate = new QPushButton(EmployeeInfo);
        pbtnUpdate->setObjectName(QString::fromUtf8("pbtnUpdate"));

        horizontalLayout_3->addWidget(pbtnUpdate);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_5);


        retranslateUi(EmployeeInfo);
        QObject::connect(pbtnClose, SIGNAL(clicked()), EmployeeInfo, SLOT(close()));

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(EmployeeInfo);
    } // setupUi

    void retranslateUi(QDialog *EmployeeInfo)
    {
        EmployeeInfo->setWindowTitle(QApplication::translate("EmployeeInfo", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EmployeeInfo", "Machine Id", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("EmployeeInfo", "Phone", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EmployeeInfo", "First Name", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("EmployeeInfo", "Another Email", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("EmployeeInfo", "Last Name", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("EmployeeInfo", "Mobile", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("EmployeeInfo", "Email", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("EmployeeInfo", "Hour Price", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(personal), QApplication::translate("EmployeeInfo", "Personal Information", 0, QApplication::UnicodeUTF8));
        pbtnAddLeave->setText(QApplication::translate("EmployeeInfo", "Add Leave", 0, QApplication::UnicodeUTF8));
        pbtnDelLeave->setText(QApplication::translate("EmployeeInfo", "Delete Leave", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(leaves), QApplication::translate("EmployeeInfo", "Leaves", 0, QApplication::UnicodeUTF8));
        pbtnAddRetribution->setText(QApplication::translate("EmployeeInfo", "Add Retribution", 0, QApplication::UnicodeUTF8));
        pbtnDelRetribution->setText(QApplication::translate("EmployeeInfo", "Delete Retribution", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(retribution), QApplication::translate("EmployeeInfo", "Retributions", 0, QApplication::UnicodeUTF8));
        pbtnAddBounce->setText(QApplication::translate("EmployeeInfo", "Add Bounce", 0, QApplication::UnicodeUTF8));
        pbtnDeleteBounce->setText(QApplication::translate("EmployeeInfo", "Delete Bounce", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(bounces), QApplication::translate("EmployeeInfo", "Bounces", 0, QApplication::UnicodeUTF8));
        pbtnClose->setText(QApplication::translate("EmployeeInfo", "Close", 0, QApplication::UnicodeUTF8));
        pbtnUpdate->setText(QApplication::translate("EmployeeInfo", "Update", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EmployeeInfo: public Ui_EmployeeInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEINFO_H
