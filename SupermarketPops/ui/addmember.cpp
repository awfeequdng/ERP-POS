#include "addmember.h"
#include "ui_addmember.h"
#include <qdebug.h>
#include <QMessageBox>
#include <QSqlQuery>

addmember::addmember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addmember)
{
    ui->setupUi(this);

    setWindowTitle("添加会员");
}

addmember::~addmember()
{
    delete ui;
}


void addmember::on_saveMemberInfo_clicked()
{
    QString memberType = ui->comboBox_memberType->currentText();
    QString beginCredit = ui->dateTimeEdit_begin->text();
    QString memberId = ui->lineEdit_memberId->text();
    QString memberName = ui->lineEdit_memberName->text();
    QString memberPhone = ui->lineEdit_memberPhone->text();
    QString BirthDay = ui->dateTimeEditBirthday->text();
    QString BirthDayWarning = ui->comboBox_birthWarning->currentText();
    QString userCredit = ui->lineEdit_userCredit->text();
    QString email = ui->lineEdit_email->text();

    //判断输入框是否为空
    if(ui->lineEdit_memberId->text().isEmpty())
    {
        QMessageBox::critical(this,tr("出错啦"), tr("请输入卡号"));
        return;
    }
    if(ui->lineEdit_memberName->text().isEmpty())
    {
        QMessageBox::critical(this,tr("出错啦"), tr("请输入姓名"));
        return;
    }
    QString str = QString(" '%1', '%2', '%3', '%4','%5', '%6', '%7', '%8','%9'").arg(memberId,memberType,memberName,beginCredit,userCredit,BirthDay,BirthDayWarning,memberPhone,email);
    QString sql = QString("INSERT INTO memberInfo (memberId,membertype,membername,\
                          beigncredits,usecredits,brithday,birthwarn,phoneNum,email)\
                            Values (%1);").arg(str);
    qDebug() << sql;
    QSqlQuery query;
    //判断插入数据库是否成功
    if(query.exec(sql))
    {
        QMessageBox::information(this, tr("操作成功"), tr("保存成功"));

    }else
    {
        QMessageBox::information(this, tr("操作失败"), tr("保存失败"));
    }
}

void addmember::on_pushButton_cancel_clicked()
{
    this->close();
}
