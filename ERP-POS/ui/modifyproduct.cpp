#include "modifyproduct.h"
#include "ui_modifyproduct.h"

Modifyproduct::Modifyproduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifyproduct)
{
    ui->setupUi(this);
}

Modifyproduct::~Modifyproduct()
{
    delete ui;
}
