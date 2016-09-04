#ifndef ADDMEMBER_H
#define ADDMEMBER_H

#include <QDialog>

namespace Ui {
class addmember;
}

class addmember : public QDialog
{
    Q_OBJECT

public:
    explicit addmember(QWidget *parent = 0);
    ~addmember();

private slots:
    void on_saveMemberInfo_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::addmember *ui;
};

#endif // ADDMEMBER_H
