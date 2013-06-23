/********************************************************************************
** Form generated from reading UI file 'newsalary.ui'
**
** Created: Wed Sep 5 07:17:49 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSALARY_H
#define UI_NEWSALARY_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewSalary
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *sss;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QDateEdit *dFromDate;
    QLabel *label_2;
    QDateEdit *dToDate;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget;
    QToolButton *toolButton;

    void setupUi(QDialog *NewSalary)
    {
        if (NewSalary->objectName().isEmpty())
            NewSalary->setObjectName(QString::fromUtf8("NewSalary"));
        NewSalary->resize(596, 462);
        verticalLayout_3 = new QVBoxLayout(NewSalary);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        sss = new QGroupBox(NewSalary);
        sss->setObjectName(QString::fromUtf8("sss"));
        verticalLayout = new QVBoxLayout(sss);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(sss);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        dFromDate = new QDateEdit(sss);
        dFromDate->setObjectName(QString::fromUtf8("dFromDate"));
        dFromDate->setDate(QDate(2011, 8, 1));
        dFromDate->setCalendarPopup(false);

        horizontalLayout->addWidget(dFromDate);

        label_2 = new QLabel(sss);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        dToDate = new QDateEdit(sss);
        dToDate->setObjectName(QString::fromUtf8("dToDate"));
        dToDate->setDate(QDate(2011, 8, 31));
        dToDate->setCalendarPopup(false);

        horizontalLayout->addWidget(dToDate);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(4, 1);

        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(sss);

        tableWidget = new QTableWidget(NewSalary);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setSortingEnabled(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(130);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(tableWidget);

        toolButton = new QToolButton(NewSalary);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        verticalLayout_2->addWidget(toolButton);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(NewSalary);

        QMetaObject::connectSlotsByName(NewSalary);
    } // setupUi

    void retranslateUi(QDialog *NewSalary)
    {
        NewSalary->setWindowTitle(QApplication::translate("NewSalary", "New Month", 0, QApplication::UnicodeUTF8));
        sss->setTitle(QApplication::translate("NewSalary", "Month Date", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewSalary", "from", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewSalary", "to", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("NewSalary", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewSalary: public Ui_NewSalary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSALARY_H
