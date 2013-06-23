/********************************************************************************
** Form generated from reading UI file 'addbounce.ui'
**
** Created: Sat Sep 1 02:50:07 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOUNCE_H
#define UI_ADDBOUNCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addbounce
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QComboBox *cbxEmployee;
    QLineEdit *leAmount;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbtnAdd;
    QPushButton *ptbtnAdd;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *addbounce)
    {
        if (addbounce->objectName().isEmpty())
            addbounce->setObjectName(QString::fromUtf8("addbounce"));
        addbounce->resize(215, 110);
        addbounce->setMinimumSize(QSize(0, 110));
        addbounce->setMaximumSize(QSize(16777215, 110));
        verticalLayout_4 = new QVBoxLayout(addbounce);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(addbounce);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(addbounce);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cbxEmployee = new QComboBox(addbounce);
        cbxEmployee->setObjectName(QString::fromUtf8("cbxEmployee"));

        verticalLayout->addWidget(cbxEmployee);

        leAmount = new QLineEdit(addbounce);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));

        verticalLayout->addWidget(leAmount);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pbtnAdd = new QPushButton(addbounce);
        pbtnAdd->setObjectName(QString::fromUtf8("pbtnAdd"));

        horizontalLayout->addWidget(pbtnAdd);

        ptbtnAdd = new QPushButton(addbounce);
        ptbtnAdd->setObjectName(QString::fromUtf8("ptbtnAdd"));

        horizontalLayout->addWidget(ptbtnAdd);

        horizontalSpacer_3 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(addbounce);

        QMetaObject::connectSlotsByName(addbounce);
    } // setupUi

    void retranslateUi(QDialog *addbounce)
    {
        addbounce->setWindowTitle(QApplication::translate("addbounce", "Add Bounce", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("addbounce", "Employee", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("addbounce", "Amount", 0, QApplication::UnicodeUTF8));
        pbtnAdd->setText(QApplication::translate("addbounce", "ok", 0, QApplication::UnicodeUTF8));
        ptbtnAdd->setText(QApplication::translate("addbounce", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class addbounce: public Ui_addbounce {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOUNCE_H
