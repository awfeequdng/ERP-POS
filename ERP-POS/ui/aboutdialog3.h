#ifndef ABOUTDIALOG3_H
#define ABOUTDIALOG3_H

#include <QDialog>

namespace Ui {
class AboutDialog3;
}

class AboutDialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog3(QWidget *parent = 0);
    ~AboutDialog3();

private:
    Ui::AboutDialog3 *ui;
};

#endif // ABOUTDIALOG3_H
