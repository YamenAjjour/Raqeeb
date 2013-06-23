    #include <QtGui/QApplication>
#include "PRE/mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QIcon>
#include<QSplashScreen>
#include <QPixmap>
#include <QTimer>
QSqlError initDb();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/icons/icons/login.png");
    a.setWindowIcon(QIcon(":/icons/icons/employeedata.svg"));
    QSplashScreen * sp = new QSplashScreen;
    sp->setPixmap(pixmap);
    sp->show();
    MainWindow w;
    QSqlError e= initDb();
    QTimer::singleShot(500,sp,SLOT(close()));
    QTimer::singleShot(500,&w,SLOT(show()));
    return a.exec();
}

QSqlError initDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","employee.dat");
    db.setDatabaseName("employee1.dat");
    if(!db.open())
        return db.lastError();
    QSqlQuery q(db);
    if(!q.exec(QLatin1String("create table if not exists emp (empid integer primary key autoincrement , firstname varchar , lastname varchar , email varchar, phone varchar , anotheremail varchar , mobile varchar , hourprice float , machineid integer unique,constraint uniqemp unique(firstname,lastname))")))
        return q.lastError();
    if(!q.exec(QLatin1String("create table if not exists bouncededuction (bounceid integer primary key autoincrement , amount float , empid not null REFERENCES emp(empid),done integer , adddate date , paydate date , type int )")))
        return q.lastError();
    if(!q.exec(QLatin1String("create table if not exists leave (id integer primary key autoincrement , leavedate date , enddate date ,reqdate date, paid int )")))
        return q.lastError();
    if(!q.exec(QLatin1String("create table if not exists emp_leave (empid REFERENCES emp(empid) on delete cascade, leaveid REFERENCES leave(id) on delete cascade)")))
        return q.lastError();
    if(!q.exec(QLatin1String("create table if not exists salaryComp(compid integer primary key autoincrement , paiddate date , numofhour integer , hourprice float , empid REFERENCES emp(empid), isremote integer, constraint uniqemp unique(empid,paiddate))")))
        return q.lastError();
    return QSqlError();

}
