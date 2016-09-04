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
    QSqlQuery querylogin;
    QString queryString2 = QString("select staffId from staff;");
    QStringList staffList;

    ui->PwdlineEdit->setFocus();
    ui->ID_comboBox->setCurrentText("admin");

    if( querylogin.exec(queryString2) )
    {
        while (querylogin.next())
        {
            QString staff = querylogin.value(0).toString();
            staffList.append(staff);
        }
    }
    ui->ID_comboBox->addItems(staffList);
}

QString LoginDialog::role = QString("");

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_LoginButton_clicked()
{
    QSqlQuery query;
    bool ok = false;
    role = ui->ID_comboBox->currentText().trimmed();
    QString inputPwd = ui->PwdlineEdit->text().trimmed();
    QString queryString = QString("select staffId from user where staffId = '%1';").arg(role);

    if(query.exec(queryString))
    {
        if ( query.next() )
        {
            QString queryString2 = QString("select * from user where staffId = '%1';").arg(role);
            if(query.exec(queryString2))
            {
                if( query.next() )
                {
                    QString user_Id = query.value(0).toString();
                    QString user_pwd = query.value(1).toString();
                    LoginUser LoginUser(user_Id,user_pwd);
                    m_loginuserlist.append(LoginUser);

                    ok = true;
                }
            }
        }else
        {
            QMessageBox::warning(this,tr("出错啦"),tr("此用户不存在!"));
            ok = false;
            return;
        }
    } else
    {
        qDebug() << "query default";
    }

    for(int i = 0; i < m_loginuserlist.count(); i++)
    {
        if (m_loginuserlist.at(i).getuser_Id() == role && m_loginuserlist.at(i).getuser_pwd() == inputPwd)
        {
            this->close();
            MainWindow *mainwindow = new MainWindow;
            mainwindow->show();
        }else
        {
            QMessageBox::warning(this,tr("出错啦"),tr("对不起，您输入的用户名或密码有错误!"));
            this->ui->ID_comboBox->clear();
            this->ui->PwdlineEdit->clear();
            this->ui->ID_comboBox->setFocus();
        }
    }
}

void LoginDialog::on_ExitLoginButton_clicked()
{
    this->close();
}
