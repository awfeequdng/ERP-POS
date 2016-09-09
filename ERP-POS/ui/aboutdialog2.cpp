#include "aboutdialog2.h"
#include "ui_aboutdialog2.h"

AboutDialog2::AboutDialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog2)
{
    ui->setupUi(this);
    setWindowTitle("注册认证");
}

AboutDialog2::~AboutDialog2()
{
    delete ui;
}
