#include "checkdialog.h"
#include "ui_checkdialog.h"

#include "serialnumber.h"
#include "checkokdialog.h"
#include "discountdialog.h"
#include <QDebug>
#include <QString>
#include <QFont>
#include <QSqlQuery>
#include <qsqlrecord>
#include <QMessageBox>
#include <QTableWidget>
#include <QDateTime>

CheckDialog::CheckDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckDialog)
{

    ui->setupUi(this);
    setWindowTitle("收银台");

    if(m_isChange = true)
    {
        getserial = new SerialNumber;
        setSerialNumber();
    }

    discountui = NULL;
    dialogui = NULL;
}

CheckDialog::~CheckDialog()
{
    delete ui;
}

//获取流水号
void CheckDialog::setSerialNumber()
{
    if ( !m_isChange )
        return;
    getserial->getSerialNumberStr();
    //    qDebug()<<getserial->getSerialNumberStr();
    ui->serialnumberlabel->setText(getserial->getSerialNumberStr());

    //设置字体的大小
    QFont ft;
    ft.setPointSize(12);
    ui->serialnumberlabel->setFont(ft);

    m_isChange = false;
}

//点击商品编号检索商品
void CheckDialog::keyPressEvent(QKeyEvent *)
{

}
void CheckDialog::addGoods(const QString &id)//相同商品添加更改数量
{

}
//算总价及数量
double totalprice = 0.0;
int totalPurchase = 0;
void CheckDialog::showTotal()
{

}

void CheckDialog::clearAll()//关闭清空
{
    ui->mainwidget->clearContents();//清除内容
    ui->mainwidget->setRowCount(0);//行数清空
    ui->shouldreceiveLabel->clear();
    ui->amoutlabel->clear();
    ui->shouldlabel->clear();
    ui->realyLineEdit->clear();
}
//整单打折实现
void CheckDialog::on_discountButton_clicked()
{

}
//整单打折实现传值的槽实现

//判断结算窗口是否关闭，决定是否结账
void CheckDialog::on_checkbutton_clicked()
{

}
//收到信号，重新生成流水号，清空结算窗口,数据库操作//点击结账，结账信息插入销售出库 //更新库存表数量//更新销售明细
void CheckDialog::slot_quit()
{

}
