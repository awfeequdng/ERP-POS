#include "rechangedialog.h"
#include "ui_rechangedialog.h"

Rechangedialog::Rechangedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rechangedialog)
{
    ui->setupUi(this);
}

Rechangedialog::~Rechangedialog()
{
    delete ui;
}
