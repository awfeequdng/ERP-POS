#include "returnstore.h"
#include "ui_returnstore.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QMessageBox>
#include <QString>

returnstore::returnstore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::returnstore)
{
    ui->setupUi(this);
    setWindowTitle("销售退货");
}

returnstore::~returnstore()
{
    delete ui;
}

//键盘监听
void returnstore::keyPressEvent(QKeyEvent *)
{
    QString serialNumber;
    QString productId;

//整单退
    if(Qt::Key_Enter && ui->serialNumBox->hasFocus() == true)
    {
        serialNumber = ui->serialNumBox->currentText();
        QString queryString = QString("select * from saledetail where serialNumber = '%1' ").arg(serialNumber);
        addGoods(queryString);
        ui->serialNumBox->clear();
    }
//单个商品退货
    if(Qt::Key_Enter && ui->productIdBox->hasFocus() == true)
    {
        productId = ui->productIdBox->currentText();
        QString queryString = QString("select * from saledetail where productId = '%1' ").arg(productId);
        addGoods(queryString);
        ui->productIdBox->clear();
    }
}
QString staffId;
QString serialNumber;
QString productId;
QString productName;
QString qualification;
QString itemNum;
QString unit;
QString retailPrice;
QString discountRate;
QString returnNum;
QString returnPrice;
QString productDate ;
QString lifeDate ;
QString warningDate ;
QString returnTotalPrice;

//添加商品根据流水号查询一单
void returnstore::addGoods(const QString &string)
{

}

void returnstore::on_outStoreButton_clicked()
{

}

void returnstore::on_exitButton_clicked()
{
    this->close();
}
