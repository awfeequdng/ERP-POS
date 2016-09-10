#include "CustomerDisplayDialog.h"
#include "ui_CustomerDisplayDialog.h"

#include "PosDialog.h"

CustomerDisplayDialog::CustomerDisplayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerDisplayDialog)
{
    ui->setupUi(this);

}

CustomerDisplayDialog::~CustomerDisplayDialog()
{
    delete ui;
}

void CustomerDisplayDialog::set_method(const QString &reallyPrice,const QString &changePrice)
{
   ui->shouldlabel->setText(reallyPrice);
   ui->changelabel->setText(changePrice);
}

void CustomerDisplayDialog::on_pushButton_clicked()
{
    this->close();

    emit signal_sendquit();
}
