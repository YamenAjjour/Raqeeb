/********************************************************************************
** Form generated from reading UI file 'addleave.ui'
**
** Created: Sat Sep 1 02:50:07 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDLEAVE_H
#define UI_ADDLEAVE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addLeave
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *deLeaveDate;
    QLabel *label_3;
    QDateEdit *deEndDate;
    QLabel *label_2;
    QComboBox *cbxPayType;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QListView *lvEmployee;
    QVBoxLayout *verticalLayout;
    QPushButton *pbtnAddEmp;
    QPushButton *pbtnRemEmp;
    QPushButton *pbtnSelectAll;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbtnAdd;
    QPushButton *pbtnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *addLeave)
    {
        if (addLeave->objectName().isEmpty())
            addLeave->setObjectName(QString::fromUtf8("addLeave"));
        addLeave->resize(441, 450);
        verticalLayout_4 = new QVBoxLayout(addLeave);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(addLeave);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deLeaveDate = new QDateEdit(groupBox);
        deLeaveDate->setObjectName(QString::fromUtf8("deLeaveDate"));

        horizontalLayout->addWidget(deLeaveDate);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        deEndDate = new QDateEdit(groupBox);
        deEndDate->setObjectName(QString::fromUtf8("deEndDate"));

        horizontalLayout->addWidget(deEndDate);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        cbxPayType = new QComboBox(groupBox);
        cbxPayType->setObjectName(QString::fromUtf8("cbxPayType"));

        horizontalLayout->addWidget(cbxPayType);

        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(5, 1);

        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(addLeave);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lvEmployee = new QListView(groupBox_2);
        lvEmployee->setObjectName(QString::fromUtf8("lvEmployee"));

        horizontalLayout_4->addWidget(lvEmployee);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pbtnAddEmp = new QPushButton(groupBox_2);
        pbtnAddEmp->setObjectName(QString::fromUtf8("pbtnAddEmp"));

        verticalLayout->addWidget(pbtnAddEmp);

        pbtnRemEmp = new QPushButton(groupBox_2);
        pbtnRemEmp->setObjectName(QString::fromUtf8("pbtnRemEmp"));

        verticalLayout->addWidget(pbtnRemEmp);

        pbtnSelectAll = new QPushButton(groupBox_2);
        pbtnSelectAll->setObjectName(QString::fromUtf8("pbtnSelectAll"));

        verticalLayout->addWidget(pbtnSelectAll);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(3, 1);

        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addWidget(groupBox_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pbtnAdd = new QPushButton(addLeave);
        pbtnAdd->setObjectName(QString::fromUtf8("pbtnAdd"));

        horizontalLayout_3->addWidget(pbtnAdd);

        pbtnCancel = new QPushButton(addLeave);
        pbtnCancel->setObjectName(QString::fromUtf8("pbtnCancel"));

        horizontalLayout_3->addWidget(pbtnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(3, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(addLeave);
        QObject::connect(pbtnCancel, SIGNAL(clicked()), addLeave, SLOT(close()));

        QMetaObject::connectSlotsByName(addLeave);
    } // setupUi

    void retranslateUi(QDialog *addLeave)
    {
        addLeave->setWindowTitle(QApplication::translate("addLeave", "Add Leave", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("addLeave", "Leave", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("addLeave", "start", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("addLeave", "end", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("addLeave", "pay type", 0, QApplication::UnicodeUTF8));
        cbxPayType->clear();
        cbxPayType->insertItems(0, QStringList()
         << QApplication::translate("addLeave", "Full Salary ", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("addLeave", "Half Salary", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("addLeave", "NO Salary", 0, QApplication::UnicodeUTF8)
        );
        groupBox_2->setTitle(QApplication::translate("addLeave", "Employees", 0, QApplication::UnicodeUTF8));
        pbtnAddEmp->setText(QApplication::translate("addLeave", "Add Employee", 0, QApplication::UnicodeUTF8));
        pbtnRemEmp->setText(QApplication::translate("addLeave", "Remove Employee", 0, QApplication::UnicodeUTF8));
        pbtnSelectAll->setText(QApplication::translate("addLeave", "Select All", 0, QApplication::UnicodeUTF8));
        pbtnAdd->setText(QApplication::translate("addLeave", "Add", 0, QApplication::UnicodeUTF8));
        pbtnCancel->setText(QApplication::translate("addLeave", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class addLeave: public Ui_addLeave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLEAVE_H
