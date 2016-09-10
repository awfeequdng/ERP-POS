#include "PosDialog.h"
#include "ui_PosDialog.h"

#include "serialnumber.h"
#include "CustomerDisplayDialog.h"
#include "discountdialog.h"
#include <QDebug>
#include <QString>
#include <QFont>
#include <QSqlQuery>
#include <qsqlrecord>
#include <QMessageBox>
#include <QTableWidget>
#include <QDateTime>

PosDialog::PosDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PosDialog)
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

PosDialog::~PosDialog()
{
    delete ui;
}

//获取流水号
void PosDialog::setSerialNumber()
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
void PosDialog::keyPressEvent(QKeyEvent *)
{

}
void PosDialog::addGoods(const QString &id)//相同商品添加更改数量
{

}
//算总价及数量
double totalprice = 0.0;
int totalPurchase = 0;
void PosDialog::showTotal()
{

}

void PosDialog::clearAll()//关闭清空
{
    ui->mainwidget->clearContents();//清除内容
    ui->mainwidget->setRowCount(0);//行数清空
    ui->shouldreceiveLabel->clear();
    ui->amoutlabel->clear();
    ui->shouldlabel->clear();
    ui->realyLineEdit->clear();
}
//整单打折实现
void PosDialog::on_discountButton_clicked()
{

}
//整单打折实现传值的槽实现

//判断结算窗口是否关闭，决定是否结账
void PosDialog::on_checkbutton_clicked()
{

}
//收到信号，重新生成流水号，清空结算窗口,数据库操作//点击结账，结账信息插入销售出库 //更新库存表数量//更新销售明细
void PosDialog::slot_quit()
{

}
