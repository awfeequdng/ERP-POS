#include "outstore.h"
#include "ui_outstore.h"
#include "QString"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDateTime>
#include <QMessageBox>

outstore::outstore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outstore)
{
    ui->setupUi(this);
    setWindowTitle("商品出库");

    //生产日期保质期的使能
    ui->datecheckBox->setChecked(false);
    ui->productdateEdit->setEnabled(false);
    ui->lifedatespinBox->setEnabled(false);
    ui->warningdateEdit->setEnabled(false);
}

outstore::~outstore()
{
    delete ui;
}

//出库时间
QString outstoreDate;
void outstore::setcurrenttime()
{
    QDateTime time = QDateTime::currentDateTime();
    outstoreDate = time.toString("yyyy-MM-dd hh:mm:ss");
    ui->outstoredateEdit->setDateTime(time);
}
void outstore::keyPressEvent(QKeyEvent *)
{
    QString productId;

    if(Qt::Key_Enter && ui->productIdEdit->hasFocus() == true)
    {

        productId = ui->productIdEdit->text();
        addGoods(productId);
        ui->productIdEdit->clear();
    }
}

void outstore::addGoods(const QString &id)
{
    QString productId = ui->productIdEdit->text();
    QString productName;
    QString qualification;
    QString itemNum;
    QString classes;
    QString productDate ;
    QString lifeDate ;
    QString warningDate ;
    QString batchNum;
    QString supplyName;

    QString queryString = QString("select * from productInfo where productId = '%1' ").arg(productId);
    QSqlQuery queryselect;
    if(queryselect.exec(queryString))
    {
        int productName_idx = queryselect.record().indexOf("productName");
        int qualification_idx = queryselect.record().indexOf("qualification");
        int itemNum_idx = queryselect.record().indexOf("itemNum");
        int classes_idx = queryselect.record().indexOf("classes");
        int productDate_idx = queryselect.record().indexOf("productDate");
        int lifeDate_idx = queryselect.record().indexOf("lifeDate");
        int warningDate_idx = queryselect.record().indexOf("warningDate");
        int batchNum_idx = queryselect.record().indexOf("batchNum");
        int supplyName_idx = queryselect.record().indexOf("supplyName");

        while(queryselect.next())
        {
            productName = queryselect.value(productName_idx).toString();
            qualification = queryselect.value(qualification_idx).toString();
            itemNum = queryselect.value(itemNum_idx).toString();
            classes = queryselect.value(classes_idx).toString();
            productDate = queryselect.value(productDate_idx).toString();
            lifeDate = queryselect.value(lifeDate_idx).toString();
            warningDate = queryselect.value(warningDate_idx).toString();
            batchNum = queryselect.value(batchNum_idx).toString();
            supplyName = queryselect.value(supplyName_idx).toString();
        }
    }else
    {
        QMessageBox::warning(this,tr("出错啦"),tr("商品不存在!"));
    }
}


void outstore::on_outButton_clicked()
{

}
//保质期的显示
void outstore::on_lifedatespinBox_valueChanged(int)
{
    QDate warningdate = ui->productdateEdit->date().addDays(ui->lifedatespinBox->value());
    ui->warningdateEdit->setDate(warningdate);
}

//到期日期的显示
void outstore::on_warningdateEdit_dateChanged(const QDate &date)
{
    QDate endtime,starttime;

    endtime = ui->warningdateEdit->date();
    starttime = ui->productdateEdit->date();

    if(endtime < starttime)
    {
        return;
    }

    if(endtime > starttime)
    {
        starttime.daysTo(endtime);
        ui->lifedatespinBox->setValue((starttime.daysTo(endtime)));
    }
}

void outstore::on_datecheckBox_clicked(bool checked)
{
    ui->productdateEdit->setEnabled(checked);
    ui->lifedatespinBox->setEnabled(checked);
    ui->warningdateEdit->setEnabled(checked);
}

void outstore::on_quitButton_clicked()
{
    this->close();
}


