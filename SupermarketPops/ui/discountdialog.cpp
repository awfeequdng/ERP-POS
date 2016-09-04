#include "discountdialog.h"
#include "ui_discountdialog.h"
#include <QDebug>

DiscountDialog::DiscountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DiscountDialog)
{
    ui->setupUi(this);
}

DiscountDialog::~DiscountDialog()
{
    delete ui;
}

void DiscountDialog::setvalue(const QString &ev3)
{
    m_should = ev3;
    qDebug()<<m_should;
}
//打折的窗口
void DiscountDialog::on_discountPrice_valueChanged(const QString &arg1)
{
    double m_price = ui->discountPrice->text().toDouble();

    ui->discountRate->setValue((m_should.toDouble() - m_price) / m_should.toDouble() * 100 );

    ui->reallyPrice->setValue(m_should.toDouble() - ui->discountPrice->text().toDouble());
}

void DiscountDialog::on_discountRate_valueChanged(const QString &arg1)
{

    double m_discountrate = ui->discountRate->text().toDouble();

    ui->discountPrice->setValue(m_should.toDouble() * m_discountrate / 100);
    qDebug()<<m_should.toDouble() * m_discountrate / 100;
    ui->reallyPrice->setValue(m_should.toDouble() - ui->discountPrice->text().toDouble());
}

void DiscountDialog::on_pushButton_2_clicked()
{
    this->close();
}

//打折确认
void DiscountDialog::on_pushButton_clicked()
{
   emit signal_sendValue(ui->reallyPrice->text());//发信号原因子窗口无法再传对象过去

   this->close();
}
