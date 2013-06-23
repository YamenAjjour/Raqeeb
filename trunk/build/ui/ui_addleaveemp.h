/********************************************************************************
** Form generated from reading UI file 'addleaveemp.ui'
**
** Created: Sat Sep 1 02:50:07 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDLEAVEEMP_H
#define UI_ADDLEAVEEMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addLeaveEmp
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cbxEmpName;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbtnAddEmp;
    QPushButton *pbtnCancel;

    void setupUi(QDialog *addLeaveEmp)
    {
        if (addLeaveEmp->objectName().isEmpty())
            addLeaveEmp->setObjectName(QString::fromUtf8("addLeaveEmp"));
        addLeaveEmp->resize(241, 73);
        addLeaveEmp->setMaximumSize(QSize(16777215, 73));
        horizontalLayout_3 = new QHBoxLayout(addLeaveEmp);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(addLeaveEmp);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cbxEmpName = new QComboBox(addLeaveEmp);
        cbxEmpName->setObjectName(QString::fromUtf8("cbxEmpName"));
        cbxEmpName->setEditable(true);

        horizontalLayout->addWidget(cbxEmpName);

        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pbtnAddEmp = new QPushButton(addLeaveEmp);
        pbtnAddEmp->setObjectName(QString::fromUtf8("pbtnAddEmp"));

        horizontalLayout_2->addWidget(pbtnAddEmp);

        pbtnCancel = new QPushButton(addLeaveEmp);
        pbtnCancel->setObjectName(QString::fromUtf8("pbtnCancel"));

        horizontalLayout_2->addWidget(pbtnCancel);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(addLeaveEmp);
        QObject::connect(pbtnCancel, SIGNAL(clicked()), addLeaveEmp, SLOT(close()));

        QMetaObject::connectSlotsByName(addLeaveEmp);
    } // setupUi

    void retranslateUi(QDialog *addLeaveEmp)
    {
        addLeaveEmp->setWindowTitle(QApplication::translate("addLeaveEmp", "Add Employee", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("addLeaveEmp", "Employee Name", 0, QApplication::UnicodeUTF8));
        pbtnAddEmp->setText(QApplication::translate("addLeaveEmp", "Add", 0, QApplication::UnicodeUTF8));
        pbtnCancel->setText(QApplication::translate("addLeaveEmp", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class addLeaveEmp: public Ui_addLeaveEmp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLEAVEEMP_H
