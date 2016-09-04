#ifndef RECHANGEDIALOG_H
#define RECHANGEDIALOG_H

#include <QDialog>

namespace Ui {
class Rechangedialog;
}

class Rechangedialog : public QDialog
{
    Q_OBJECT

public:
    explicit Rechangedialog(QWidget *parent = 0);
    ~Rechangedialog();

private:
    Ui::Rechangedialog *ui;
};

#endif // RECHANGEDIALOG_H
