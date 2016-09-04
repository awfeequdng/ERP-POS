#ifndef CHECKDIALOG_H
#define CHECKDIALOG_H

#include <QDialog>
#include "serialnumber.h"
#include "discountdialog.h"
#include "checkokdialog.h"
#include <QList>
#include <QMap>

namespace Ui {
class CheckDialog;
}

class CheckDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckDialog(QWidget *parent = 0);
    ~CheckDialog();

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
    Ui::CheckDialog *ui;

    SerialNumber *getserial;

    bool m_isChange;

    DiscountDialog *discountui;

    CheckOkDialog *dialogui;

    QString saleDate;

    QMap<QString, QString> m_productIdAndPriceMap;
};

#endif // CHECKDIALOG_H
