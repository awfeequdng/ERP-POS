#ifndef INSTORE_H
#define INSTORE_H

#include <QDialog>

namespace Ui {
class instore;
}

class instore : public QDialog
{
    Q_OBJECT

public:
    explicit instore(QWidget *parent = 0);
    ~instore();

    //获取当前时间的方法
    void setcurrenttime();

    void addInfo();

protected:
    bool eventFilter(QObject *target, QEvent *event);

private slots:
    void on_instorepushbutton_clicked();

    void on_quitButton_clicked();

    void on_lifedatespinBox_valueChanged(int arg1);

    void on_warningdateEdit_dateChanged(const QDate &date);

    void on_datecheckBox_clicked(bool checked);

    void on_retailEdit_textChanged(const QString &arg1);

private:
    Ui::instore *ui;

    QString instoreDate;
    bool m_isFourceId;
};

#endif // INSTORE_H
