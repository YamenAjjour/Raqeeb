/********************************************************************************
** Form generated from reading UI file 'detaileduserdialog.ui'
**
** Created: Sat Sep 1 02:50:07 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILEDUSERDIALOG_H
#define UI_DETAILEDUSERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_detailedUserDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QListWidget *lwForg;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QListWidget *lgNightSh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbtnClose;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *detailedUserDialog)
    {
        if (detailedUserDialog->objectName().isEmpty())
            detailedUserDialog->setObjectName(QString::fromUtf8("detailedUserDialog"));
        detailedUserDialog->resize(361, 414);
        verticalLayout_2 = new QVBoxLayout(detailedUserDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(detailedUserDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lwForg = new QListWidget(groupBox);
        lwForg->setObjectName(QString::fromUtf8("lwForg"));

        verticalLayout_3->addWidget(lwForg);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(detailedUserDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lgNightSh = new QListWidget(groupBox_2);
        lgNightSh->setObjectName(QString::fromUtf8("lgNightSh"));

        verticalLayout_4->addWidget(lgNightSh);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbtnClose = new QPushButton(detailedUserDialog);
        pbtnClose->setObjectName(QString::fromUtf8("pbtnClose"));

        horizontalLayout->addWidget(pbtnClose);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 3);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 10);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(detailedUserDialog);
        QObject::connect(pbtnClose, SIGNAL(clicked()), detailedUserDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(detailedUserDialog);
    } // setupUi

    void retranslateUi(QDialog *detailedUserDialog)
    {
        detailedUserDialog->setWindowTitle(QApplication::translate("detailedUserDialog", "Details", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("detailedUserDialog", "Times User has forgoten to sign out", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("detailedUserDialog", "nightshift", 0, QApplication::UnicodeUTF8));
        pbtnClose->setText(QApplication::translate("detailedUserDialog", "close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class detailedUserDialog: public Ui_detailedUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILEDUSERDIALOG_H
