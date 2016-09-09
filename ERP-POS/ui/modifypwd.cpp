#include "modifypwd.h"
#include "ui_modifypwd.h"
#include "logindialog.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

modifypwd::modifypwd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifypwd)
{
    ui->setupUi(this);
    setWindowTitle("修改密码");
}

modifypwd::~modifypwd()
{
    delete ui;
}

void modifypwd::on_okpushButton_clicked()
{
    QSqlQuery query;
    QString queryselect = QString(" select password from user where staffId = '%1';").arg(LoginDialog::staffId);
        query.exec(queryselect);
        query.next();
        if(ui->originalLineEdit->text().isEmpty())
            QMessageBox::warning(this, "请输入密码", "请输入旧密码和新密码", QMessageBox::Ok);
        else if(ui->originalLineEdit->text() != query.value(0).toString())
        {
            QMessageBox::warning(this, "密码错误", "输入的旧密码错误", QMessageBox::Ok);
            ui->originalLineEdit->setFocus();
        }
        else
        {
            if(ui->newPwdLineEdit->text() == ui->confirmPwdLineEdit->text())
            {
                QString newPassword = ui->newPwdLineEdit->text();
                QString sql = QString("update user set password = '%1' where staffId = '%2'").arg(newPassword,LoginDialog::staffId);
                if(query.exec(sql))//更新密码
                {
                    QMessageBox::information(this, tr("修改密码"), tr("修改密码成功！"), QMessageBox::Ok);
                }
                else
                {
                    QMessageBox::information(this, tr("修改密码"), tr("修改密码失败！"), QMessageBox::Ok);
                }
            }
            else
                QMessageBox::warning(this, "修改密码失败", "新密码两次输入不一致！", QMessageBox::Ok);
        }
}

void modifypwd::on_quitpushButton_clicked()
{
    this->close();
}

void modifypwd::on_helppushButton_clicked()
{

}
