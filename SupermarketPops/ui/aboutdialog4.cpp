#include "aboutdialog4.h"
#include "ui_aboutdialog4.h"

AboutDialog4::AboutDialog4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog4)
{
    ui->setupUi(this);
    setWindowTitle("关于");
}

AboutDialog4::~AboutDialog4()
{
    delete ui;
}
