#ifndef PosDialog_H
#define PosDialog_H

#include <QDialog>
#include "serialnumber.h"
#include "discountdialog.h"
#include "CustomerDisplayDialog.h"
#include <QList>
#include <QMap>

namespace Ui {
class PosDialog;
}

class PosDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PosDialog(QWidget *parent = 0);
    ~PosDialog();

    //获取流水号
    void setSerialNumber();

    virtual void keyPressEvent(QKeyEvent *);

    void addGoods(const QString &id);

    void showTotal();

    void acountChange();

    void clearAll();

private slots:


    void on_checkbutton_clicked();

    void on_discountButton_clicked();

    void slot_quit();

private:
    Ui::PosDialog *ui;

    SerialNumber *getserial;

    bool m_isChange;

    DiscountDialog *discountui;

    CustomerDisplayDialog *dialogui;

    QString saleDate;

    QMap<QString, QString> m_productIdAndPriceMap;
};

#endif // PosDialog_H
