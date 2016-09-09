#include "aboutdialog1.h"
#include "ui_aboutdialog1.h"

AboutDialog1::AboutDialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog1)
{
    ui->setupUi(this);
    setWindowTitle("购买软件");
}

AboutDialog1::~AboutDialog1()
{
    delete ui;
}
