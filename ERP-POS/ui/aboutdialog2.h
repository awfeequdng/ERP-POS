#ifndef ABOUTDIALOG2_H
#define ABOUTDIALOG2_H

#include <QDialog>

namespace Ui {
class AboutDialog2;
}

class AboutDialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog2(QWidget *parent = 0);
    ~AboutDialog2();

private:
    Ui::AboutDialog2 *ui;
};

#endif // ABOUTDIALOG2_H
