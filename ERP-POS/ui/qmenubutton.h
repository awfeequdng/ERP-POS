#ifndef QMENUBUTTON_H
#define QMENUBUTTON_H


#include <QPushButton>

class QMenu;
class QMenuButton : public QPushButton

{
    Q_OBJECT

public:
    explicit QMenuButton(QWidget *parent = 0);//只能显示转换

    QMenu * getmenu();
private slots:
    void popupmenu();
private:
    QMenu * menu;
};


#endif // QMENUBUTTON_H
