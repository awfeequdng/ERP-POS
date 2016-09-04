#include "logindialog.h"
#include "mainwindow.h"

#include <QApplication>
#include <QtSql/QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSystemSemaphore>
#include <QSharedMemory>
#include <QMessageBox>
#include <QSqlQuery>

static bool createConnection()
{

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("pops.db");


    if (!db.open()){
        qCritical("Can't open database:%s(%s)",
                  db.lastError().text().toLocal8Bit().data(),
                  qt_error_string().toLocal8Bit().data());
        return false;
    }
    QSqlQuery query;
    if(query.exec("select * from user"))
    {
        qDebug() << "success";
    }
    else
    {
        qDebug() << "failure" << query.lastError().text();
    }
    return true;
}

void closeConnection()
{
    QSqlDatabase::database().close();
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //主窗口实例只能运行一次
    QSystemSemaphore systemSemaphore("超市收银",1,QSystemSemaphore::Open);

    systemSemaphore.acquire();// 在临界区操作共享内存   SharedMemory

    QSharedMemory sharedMemory("SystemObject");// 全局对象名

    if (!sharedMemory.create(1))// 如果全局对象已存在则退出
    {
        QMessageBox::warning(0, "温馨提示 ...", "超市收银系统已经运行，不能再次运行");

        systemSemaphore.release();// 如果是 Unix 系统，会自动释放。

        return 0;
    }

    systemSemaphore.release();// 临界区

    if (!createConnection())
    {
        qDebug() << "connect default ";
        return 1;
    } else
    {
        qDebug() << "connect success ";
    }

    LoginDialog w;
    w.show();

    int res = app.exec();
    closeConnection();
    return res;
}
