#ifndef DETAILEDUSERDIALOG_H
#define DETAILEDUSERDIALOG_H

#include <QDialog>

namespace Ui {
    class detailedUserDialog;
}

class detailedUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit detailedUserDialog(QWidget *parent = 0);
    ~detailedUserDialog();
    void setData(QString item, int mode);


private:
    Ui::detailedUserDialog *ui;
};

#endif // DETAILEDUSERDIALOG_H
