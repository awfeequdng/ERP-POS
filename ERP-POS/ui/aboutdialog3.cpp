#include "aboutdialog3.h"
#include "ui_aboutdialog3.h"

AboutDialog3::AboutDialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog3)
{
    ui->setupUi(this);
    setWindowTitle("客户服务");
}

AboutDialog3::~AboutDialog3()
{
    delete ui;
}
