#include "logindialog.h"
#include "ui_logindialog.h"

#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QFont>
#include <QRegExp>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("超市收银系统");
    //默认
    QSqlQuery query;
    QString queryStr = QString("select staffId from staff;");
    QStringList staffList;

    ui->pwdLineEdit->setFocus();
    ui->idComboBox->setCurrentText("admin");

    if( query.exec(queryStr) )
    {
        while (query.next())
        {
            QString staff = query.value(0).toString();
            staffList.append(staff);
        }
    }
    ui->idComboBox->addItems(staffList);
}

QString LoginDialog::staffId = QString("");

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_LoginButton_clicked()
{
    QSqlQuery query;
    staffId = ui->idComboBox->currentText().trimmed();
    QString inputPwd = ui->pwdLineEdit->text().trimmed();
    QString queryString = QString("select 1 from user where staffId='%1' and password='%2';").arg(staffId).arg(inputPwd);

    if(query.exec(queryString))
    {
        if(query.next())
        {
            this->close();
            MainWindow *mainwindow = new MainWindow;
            mainwindow->show();
        }
        else
        {
            QMessageBox::warning(this,tr("出错啦"),tr("对不起，您输入的用户名或密码有错误!"));
            return;
        }
    }
}

void LoginDialog::on_ExitLoginButton_clicked()
{
    this->close();
}
