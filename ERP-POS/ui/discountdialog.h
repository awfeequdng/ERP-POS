#ifndef DISCOUNTDIALOG_H
#define DISCOUNTDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class DiscountDialog;
}

class DiscountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DiscountDialog(QWidget *parent = 0);
    ~DiscountDialog();

    void setvalue(const QString &);

signals:
    void signal_sendValue(QString);

private slots:
    void on_discountPrice_valueChanged(const QString &arg1);

    void on_discountRate_valueChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::DiscountDialog *ui;

    QString m_should;

    QString m_really;
};

#endif // DISCOUNTDIALOG_H
