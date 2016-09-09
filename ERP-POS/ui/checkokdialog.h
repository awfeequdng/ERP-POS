#ifndef CHECKOKDIALOG_H
#define CHECKOKDIALOG_H

#include <QDialog>

namespace Ui {
class CheckOkDialog;
}

class CheckOkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckOkDialog(QWidget *parent = 0);
    ~CheckOkDialog();

    void set_method(const QString &,const QString &);

signals:
    void signal_sendquit();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CheckOkDialog *ui;

    QString reallyPrice;

    QString changePrice;
};

#endif // CHECKOKDIALOG_H
