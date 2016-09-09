#ifndef OUTSTORE_H
#define OUTSTORE_H

#include <QDialog>

namespace Ui {
class outstore;
}

class outstore : public QDialog
{
    Q_OBJECT

public:
    explicit outstore(QWidget *parent = 0);
    ~outstore();

    virtual void keyPressEvent(QKeyEvent *);

    void setcurrenttime();

    void addGoods(const QString &id);

    void on_lifedatespinBox_valueChanged(int arg1);

    void on_warningdateEdit_dateChanged(const QDate &date);

    void on_datecheckBox_clicked(bool checked);

private slots:
    void on_outButton_clicked();

    void on_quitButton_clicked();


private:
    Ui::outstore *ui;
};

#endif // OUTSTORE_H
