#ifndef MODIFYPWD_H
#define MODIFYPWD_H

#include <QDialog>

namespace Ui {
class modifypwd;
}

class modifypwd : public QDialog
{
    Q_OBJECT

public:
    explicit modifypwd(QWidget *parent = 0);
    ~modifypwd();

private slots:
    void on_okpushButton_clicked();

    void on_quitpushButton_clicked();

    void on_helppushButton_clicked();

private:
    Ui::modifypwd *ui;
};

#endif // MODIFYPWD_H
