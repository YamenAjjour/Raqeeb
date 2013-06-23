/********************************************************************************
** Form generated from reading UI file 'userhandlogdialog.ui'
**
** Created: Sat Sep 1 02:50:07 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERHANDLOGDIALOG_H
#define UI_USERHANDLOGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UserHandlogDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableView *tw_usersInfo;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbtnAddEmployee;
    QPushButton *pbtnDelEmp;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbtn_close;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *UserHandlogDialog)
    {
        if (UserHandlogDialog->objectName().isEmpty())
            UserHandlogDialog->setObjectName(QString::fromUtf8("UserHandlogDialog"));
        UserHandlogDialog->resize(628, 575);
        verticalLayout_2 = new QVBoxLayout(UserHandlogDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(24);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tw_usersInfo = new QTableView(UserHandlogDialog);
        tw_usersInfo->setObjectName(QString::fromUtf8("tw_usersInfo"));

        verticalLayout->addWidget(tw_usersInfo);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pbtnAddEmployee = new QPushButton(UserHandlogDialog);
        pbtnAddEmployee->setObjectName(QString::fromUtf8("pbtnAddEmployee"));

        horizontalLayout->addWidget(pbtnAddEmployee);

        pbtnDelEmp = new QPushButton(UserHandlogDialog);
        pbtnDelEmp->setObjectName(QString::fromUtf8("pbtnDelEmp"));

        horizontalLayout->addWidget(pbtnDelEmp);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbtn_close = new QPushButton(UserHandlogDialog);
        pbtn_close->setObjectName(QString::fromUtf8("pbtn_close"));

        horizontalLayout->addWidget(pbtn_close);

        horizontalSpacer_3 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 5);
        horizontalLayout->setStretch(4, 2);
        horizontalLayout->setStretch(5, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(UserHandlogDialog);
        QObject::connect(pbtn_close, SIGNAL(clicked()), UserHandlogDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(UserHandlogDialog);
    } // setupUi

    void retranslateUi(QDialog *UserHandlogDialog)
    {
        UserHandlogDialog->setWindowTitle(QApplication::translate("UserHandlogDialog", "Employees Management", 0, QApplication::UnicodeUTF8));
        pbtnAddEmployee->setText(QApplication::translate("UserHandlogDialog", "Add Employee", 0, QApplication::UnicodeUTF8));
        pbtnDelEmp->setText(QApplication::translate("UserHandlogDialog", "Del  Employee", 0, QApplication::UnicodeUTF8));
        pbtn_close->setText(QApplication::translate("UserHandlogDialog", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserHandlogDialog: public Ui_UserHandlogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERHANDLOGDIALOG_H
