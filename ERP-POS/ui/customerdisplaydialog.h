#ifndef CustomerDisplayDialog_H
#define CustomerDisplayDialog_H

#include <QDialog>

namespace Ui {
class CustomerDisplayDialog;
}

class CustomerDisplayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerDisplayDialog(QWidget *parent = 0);
    ~CustomerDisplayDialog();

    void set_method(const QString &,const QString &);

signals:
    void signal_sendquit();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CustomerDisplayDialog *ui;

    QString reallyPrice;

    QString changePrice;
};

#endif // CustomerDisplayDialog_H
