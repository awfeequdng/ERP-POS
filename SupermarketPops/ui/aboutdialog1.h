#ifndef ABOUTDIALOG1_H
#define ABOUTDIALOG1_H

#include <QDialog>

namespace Ui {
class AboutDialog1;
}

class AboutDialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog1(QWidget *parent = 0);
    ~AboutDialog1();

private:
    Ui::AboutDialog1 *ui;
};

#endif // ABOUTDIALOG1_H
