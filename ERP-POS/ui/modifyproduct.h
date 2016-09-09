#ifndef MODIFYPRODUCT_H
#define MODIFYPRODUCT_H

#include <QDialog>

namespace Ui {
class Modifyproduct;
}

class Modifyproduct : public QDialog
{
    Q_OBJECT

public:
    explicit Modifyproduct(QWidget *parent = 0);
    ~Modifyproduct();

private:
    Ui::Modifyproduct *ui;
};

#endif // MODIFYPRODUCT_H
