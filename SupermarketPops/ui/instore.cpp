#include "instore.h"
#include "ui_instore.h"
#include <QSqlQuery>
#include <Qsqlrecord>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QDate>
#include <QMessageBox>
#include <QEvent>

instore::instore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instore)
{
    ui->setupUi(this);
    setWindowTitle("商品入库[增加]");
    m_isFourceId = false;

    //生产日期保质期的使能
    ui->datecheckBox->setChecked(false);
    ui->productdateEdit->setEnabled(false);
    ui->lifedatespinBox->setEnabled(false);
    ui->warningdateEdit->setEnabled(false);

    //供应商添加到ui
    QString mystring = "select supplyname from supplyInfo;";
    QSqlQuery query;
    QStringList nameList;
    if(query.exec(mystring))
    {
        QString supplyname;
        //qDebug() << " select success ";
        while(query.next())
        {
            supplyname = query.value(0).toString();
            nameList.append(supplyname);
        }
    }
    ui->supplyBox->addItems(nameList);
    ui->supplyBox->setCurrentText("供应商名称");
    ui->productIdEdit->installEventFilter(this);
    ui->productNameEdit->installEventFilter(this);
    ui->productIdEdit->setFocus();
}

instore::~instore()
{
    delete ui;
}
//入库时间
void instore::setcurrenttime()
{
    QDateTime time = QDateTime::currentDateTime();
    instoreDate = time.toString("yyyy年MM月dd日 hh:mm:ss");
    ui->dateTimeEdit->setDateTime(time);
}
//键盘监听
bool instore::eventFilter(QObject *target, QEvent *event)
{
    if ( target == ui->productIdEdit )
    {

        if ( event->type() == QEvent::FocusIn )
        {
//            qDebug() << "focus in product id edit ";
            m_isFourceId = true;
        } else
        {
//            qDebug() << "not focus in product id edit " << m_isFourceId;
        }
    }
    if ( target == ui->productNameEdit )
    {
        if ( event->type() == QEvent::FocusIn )
        {
//            qDebug() << "focus in product id edit ";
            if ( m_isFourceId )
            {
                addInfo();
                m_isFourceId = false;
            }
//            m_isFourceId = true;
        }
    }
    return QWidget::eventFilter(target, event);
}
//添加到Ui
void instore::addInfo()
{
    QString ui_Id = ui->productIdEdit->text();
    if ( ui_Id.isEmpty() )
        return;
    QSqlQuery query;//判断商品存在
    QString judgesql = QString("select productId from store where productId = '%1';").arg(ui_Id);
//    qDebug() << "sql query " << judgesql;
    if(query.exec(judgesql))
    {
        if(query.next() == true)
        {
            QString queryInsert = QString("select * from productInfo where productId = '%1';")
                    .arg(ui_Id);
//            qDebug() << "quwry sql " << queryInsert;
            if(query.exec(queryInsert))
            {
                if ( query.next() )
                {
                int name_idx = query.record().indexOf("productName");
                int unit_idx = query.record().indexOf("unit");
                int itemNum_idx = query.record().indexOf("itemNum");
                int qualification_idx = query.record().indexOf("qualification");
                int class_idx = query.record().indexOf("classes");
                int supplyName_idx = query.record().indexOf("supplyName");
                int brand_idx = query.record().indexOf("brand");
                int batchNum_idx =query.record().indexOf("batchNum");
                int warningNum_idx = query.record().indexOf("warningNum");

                QString name = query.value(name_idx).toString();
                QString unit = query.value(unit_idx).toString();
                QString itemNum = query.value(itemNum_idx).toString();
                QString qualification = query.value(qualification_idx).toString();
                QString classes = query.value(class_idx).toString();
                QString supplyName = query.value(supplyName_idx).toString();
                QString brand = query.value(brand_idx).toString();
                QString batchNum = query.value(batchNum_idx).toString();
                QString warningNum = query.value(warningNum_idx).toString();
//                qDebug() << "select query value : " << name;

                ui->productNameEdit->setText(name);
                ui->unitBox->setCurrentText(unit);
                ui->itemNumEdit->setText(itemNum);
                ui->qualificationBox->setCurrentText(qualification);
                ui->classBox->setCurrentText(classes);
                ui->supplyBox->setCurrentText(supplyName);
                ui->brandBox->setCurrentText(brand);
                ui->batchNumEdit->setText(batchNum);
                ui->warningNumEdit->setText(warningNum);

                ui->productNameEdit->setEnabled(false);
                ui->unitBox->setEnabled(false);
                ui->itemNumEdit->setEnabled(false);
                ui->qualificationBox->setEnabled(false);
                ui->classBox->setEnabled(false);
                ui->supplyBox->setEnabled(false);
                ui->datecheckBox->setEnabled(false);
                ui->brandBox->setEnabled(false);
                ui->batchNumEdit->setEnabled(false);
                ui->warningNumEdit->setEnabled(false);
                ui->discountSchemecheckBox->setEnabled(false);
                ui->creditSchemecheckBox->setEnabled(false);
                ui->purchaseEdit->setEnabled(true);
                ui->retailEdit->setEnabled(true);
                ui->memberpriceEdit->setEnabled(true);
                ui->instoreNumEdit->setEnabled(true);
                }
            }
        }else
        {
            ui->productNameEdit->setEnabled(true);
            ui->unitBox->setEnabled(true);
            ui->itemNumEdit->setEnabled(true);
            ui->qualificationBox->setEnabled(true);
            ui->classBox->setEnabled(true);
            ui->supplyBox->setEnabled(true);
            ui->datecheckBox->setEnabled(true);
            ui->brandBox->setEnabled(true);
            ui->batchNumEdit->setEnabled(true);
            ui->warningNumEdit->setEnabled(true);
            ui->discountSchemecheckBox->setEnabled(true);
            ui->creditSchemecheckBox->setEnabled(true);
            ui->purchaseEdit->setEnabled(true);
            ui->retailEdit->setEnabled(true);
            ui->memberpriceEdit->setEnabled(true);
            ui->instoreNumEdit->setEnabled(true);
        }
    }
}
//入库确认按钮
QString profitRate;
void instore::on_instorepushbutton_clicked()
{

}
//入库取消按钮
void instore::on_quitButton_clicked()
{
    this->close();
}

//保质期的显示
void instore::on_lifedatespinBox_valueChanged(int)
{
    QDate warningdate = ui->productdateEdit->date().addDays(ui->lifedatespinBox->value());
    ui->warningdateEdit->setDate(warningdate);
}

//到期日期的显示
void instore::on_warningdateEdit_dateChanged(const QDate &date)
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

//生产日期的使能功能
void instore::on_datecheckBox_clicked(bool checked)
{
    ui->productdateEdit->setEnabled(checked);
    ui->lifedatespinBox->setEnabled(checked);
    ui->warningdateEdit->setEnabled(checked);
}

//利润率的实时显示
void instore::on_retailEdit_textChanged(const QString &value)
{
    QString purchasePrice = ui->purchaseEdit->text();
    QString retailPrice = ui->retailEdit->text();

    profitRate = QString::number((retailPrice.toDouble() - purchasePrice.toDouble())
                                         / purchasePrice.toDouble() *100)+ "\%";
    ui->profitrateEdit->setText(profitRate);
}


