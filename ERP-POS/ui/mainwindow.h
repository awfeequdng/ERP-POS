#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPrinter>
#include <productscaninfo.h>
#include <instoreanalysis.h>
#include <saledetail.h>
#include <saleanalysis.h>
#include "discountgoodinfo.h"

class CheckDialog;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void closeTab();
    virtual void keyPressEvent(QKeyEvent *);

private slots:

    void setCashierPermiss();

    void on_inStoreButton_clicked();

    void on_checkoutButton_clicked();

    void on_scanButton_clicked();

    void removeSubTab(int index);

    void on_salesReturnButton_clicked();


    void on_instoreStatisticsButton_clicked();

    void on_saleStatisticsButton_clicked();

    void on_saleDetailButton_clicked();

    void on_outstoreButton_clicked();

    void on_outstoreStatisticsButton_clicked();

    void timerUpDate();

    void slot_clicked(QAction *);

    void on_paintButton_clicked();

    void on_exportButton_clicked();

    void on_helpButton_clicked();

    void on_outButton_clicked();



    void on_memberButton_clicked();

    void on_addMemberButton_clicked();

    void on_creditsHistoryButton_clicked();

    void on_expenseDetailButton_clicked();

    void on_incomeDetailButton_clicked();

    void on_memberRechangeButton_clicked();

    void on_rechangeStatisticsButton_clicked();

    void on_memberCnfigurationButton_clicked();

    void on_creditsSetButton_clicked();

    void on_discountSetButton_clicked();

    void on_birthdayButton_clicked();

    void on_parameterConfigurationButton_clicked();

    void on_modifyPwdButton_clicked();

    void on_staffGoveButton_clicked();

    void on_dataMangeButton_clicked();

    void on_importButton_clicked();

    void on_back_upButton_clicked();

    void on_exchangeButton_clicked();

    void on_exchangeStatisticsButton_clicked();

    void on_modifyButton_clicked();

    void on_modifyStatisticsButton_clicked();

    void on_dismountingButton_clicked();

    void on_otherSetButton_clicked();

    void on_helpButton_2_clicked();

    void on_purchaseButton_clicked();

    void on_registerButton_clicked();

    void on_webButton_clicked();

    void on_serviceButton_clicked();

    void on_QQButton_clicked();

    void on_updateButton_clicked();

    void on_aboutButton_clicked();

    void doPrintPreview();

    void plotPic(QPrinter *);
    void on_refreshButton_clicked();

    void checkBoxChange(int row, int col);

    void on_pushButton_right_clicked();

private:
    Ui::MainWindow *ui;

    CheckDialog *checkoutui;

    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action4;
    QAction *action5;
    QAction *action6;

    QMainWindow *mainwindowui;

protected:
    virtual void resizeEvent (QResizeEvent *);

    QList <ProductScanInfo> m_list;
    QList <InstoreAnalysis> m_list2;
    QList <SaleDetail> m_list4;
    QList <SaleAnalysis> m_list5;
    discountGoodInfoList selectedLeftRecordsList;
    discountGoodInfoList selectedRightRecordsList;
    discountGoodInfoList leftRecordsList;
    discountGoodInfoList rightRecordsList;

    void updateLeftList(discountGoodInfoList InfoList);
    void getLeftSelectedRecordsList();
    void getLeftRecordsList();
    void getRightSelectedRecordsList();
    void getRightRecordsList();
};

#endif // MAINWINDOW_H
