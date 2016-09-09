#include "checkokdialog.h"
#include "ui_checkokdialog.h"

#include "checkdialog.h"

CheckOkDialog::CheckOkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckOkDialog)
{
    ui->setupUi(this);

}

CheckOkDialog::~CheckOkDialog()
{
    delete ui;
}

void CheckOkDialog::set_method(const QString &reallyPrice,const QString &changePrice)
{
   ui->shouldlabel->setText(reallyPrice);
   ui->changelabel->setText(changePrice);
}

void CheckOkDialog::on_pushButton_clicked()
{
    this->close();

    emit signal_sendquit();
}
