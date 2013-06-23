/********************************************************************************
** Form generated from reading UI file 'adduser.ui'
**
** Created: Sat Sep 1 02:50:07 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSER_H
#define UI_ADDUSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddUser
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *leID;
    QLineEdit *leFirstName;
    QLineEdit *leSecondName;
    QLineEdit *leEmail;
    QLineEdit *lePhone;
    QLineEdit *leMobile;
    QLineEdit *leAnotherEmail;
    QLineEdit *leHourPrice;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbtnAdd;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pbtnCancel;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *AddUser)
    {
        if (AddUser->objectName().isEmpty())
            AddUser->setObjectName(QString::fromUtf8("AddUser"));
        AddUser->resize(246, 258);
        AddUser->setMaximumSize(QSize(16777215, 258));
        verticalLayout_4 = new QVBoxLayout(AddUser);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(AddUser);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(AddUser);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_7 = new QLabel(AddUser);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_3 = new QLabel(AddUser);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(AddUser);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(AddUser);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(AddUser);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_8 = new QLabel(AddUser);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        leID = new QLineEdit(AddUser);
        leID->setObjectName(QString::fromUtf8("leID"));

        verticalLayout_2->addWidget(leID);

        leFirstName = new QLineEdit(AddUser);
        leFirstName->setObjectName(QString::fromUtf8("leFirstName"));

        verticalLayout_2->addWidget(leFirstName);

        leSecondName = new QLineEdit(AddUser);
        leSecondName->setObjectName(QString::fromUtf8("leSecondName"));

        verticalLayout_2->addWidget(leSecondName);

        leEmail = new QLineEdit(AddUser);
        leEmail->setObjectName(QString::fromUtf8("leEmail"));

        verticalLayout_2->addWidget(leEmail);

        lePhone = new QLineEdit(AddUser);
        lePhone->setObjectName(QString::fromUtf8("lePhone"));

        verticalLayout_2->addWidget(lePhone);

        leMobile = new QLineEdit(AddUser);
        leMobile->setObjectName(QString::fromUtf8("leMobile"));

        verticalLayout_2->addWidget(leMobile);

        leAnotherEmail = new QLineEdit(AddUser);
        leAnotherEmail->setObjectName(QString::fromUtf8("leAnotherEmail"));

        verticalLayout_2->addWidget(leAnotherEmail);

        leHourPrice = new QLineEdit(AddUser);
        leHourPrice->setObjectName(QString::fromUtf8("leHourPrice"));

        verticalLayout_2->addWidget(leHourPrice);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pbtnAdd = new QPushButton(AddUser);
        pbtnAdd->setObjectName(QString::fromUtf8("pbtnAdd"));

        horizontalLayout_2->addWidget(pbtnAdd);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pbtnCancel = new QPushButton(AddUser);
        pbtnCancel->setObjectName(QString::fromUtf8("pbtnCancel"));

        horizontalLayout_2->addWidget(pbtnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 2);

        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3->setStretch(0, 1);

        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(AddUser);

        QMetaObject::connectSlotsByName(AddUser);
    } // setupUi

    void retranslateUi(QDialog *AddUser)
    {
        AddUser->setWindowTitle(QApplication::translate("AddUser", "Add Employee", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddUser", "ID", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddUser", "First Name", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AddUser", "Second Name", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddUser", "Email", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddUser", "phone", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AddUser", "Mobile", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AddUser", "Another Email", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("AddUser", "Hour Price", 0, QApplication::UnicodeUTF8));
        pbtnAdd->setText(QApplication::translate("AddUser", "Add", 0, QApplication::UnicodeUTF8));
        pbtnCancel->setText(QApplication::translate("AddUser", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddUser: public Ui_AddUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSER_H
