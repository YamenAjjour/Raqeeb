#include <QtGui/QApplication>
#include "PRE/mainwindow.h"
#include <QtSql/QSqlDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","rdb");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("rdb");
    db.setPassword("0");
    db.setPort(5432);
    db.setUserName("postgres");
    MainWindow w;
    w.show();
    return a.exec();
}
