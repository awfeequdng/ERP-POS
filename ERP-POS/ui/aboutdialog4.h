#ifndef ABOUTDIALOG4_H
#define ABOUTDIALOG4_H

#include <QDialog>

namespace Ui {
class AboutDialog4;
}

class AboutDialog4 : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog4(QWidget *parent = 0);
    ~AboutDialog4();

private:
    Ui::AboutDialog4 *ui;
};

#endif // ABOUTDIALOG4_H
