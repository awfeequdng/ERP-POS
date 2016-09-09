#ifndef RETURNSTORE_H
#define RETURNSTORE_H

#include <QDialog>

namespace Ui {
class returnstore;
}

class returnstore : public QDialog
{
    Q_OBJECT

public:
    explicit returnstore(QWidget *parent = 0);
    ~returnstore();

    void keyPressEvent(QKeyEvent *);

    void addGoods(const QString &serialNum);
private slots:
    void on_outStoreButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::returnstore *ui;
};

#endif // RETURNSTORE_H
