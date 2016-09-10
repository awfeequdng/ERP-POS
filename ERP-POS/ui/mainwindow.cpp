#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include "instore.h"
#include "PosDialog.h"
#include "returnstore.h"
#include "outstore.h"
#include "store.h"
#include "dbsql.h"
#include "productscaninfo.h"
#include "instoreanalysis.h"
#include "saleanalysis.h"
#include "saledetail.h"
#include "modifypwd.h"
#include "aboutdialog1.h"
#include "aboutdialog2.h"
#include "aboutdialog3.h"
#include "aboutdialog4.h"
#include "addmember.h"
#include "discountgoodinfo.h"
#include "logindialog.h"

#include <QMetaType>
#include <QMessageBox>
#include <QTabWidget>
#include <QPalette>
#include <QPainter>
#include <QPixmap>
#include <QDateTime>
#include <QTimer>
#include <QMenu>
#include <QAction>
#include <QList>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QAxObject>/*导出excel*/

#include <QPrinter>
#include <QPrintDialog>/*打印对话框类*/
#include <QtPrintSupport>
#include <QPageSetupDialog>/*打印页面设置*/
#include <QPrintPreviewDialog>/*打印预览对话框类*/
#include <QFont>
#include <QHeaderView>/*表头属性*/
#include <Qt>
#include <QFile>
#include <QProcess>
#include <QWebView>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("超市收银系统");
    this->showMaximized();//窗口自适应屏幕大小
    checkoutui = NULL;//下边checkui要判断
    closeTab();//关闭tab的
    ui->TabWidget->clear();//清空中间选项卡，显示背景

    QTimer *timer = new QTimer(this);//定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpDate()));
    timer->start(1000);

    //其他按钮的下拉实现
    QMenu* menu = ui->otherButton->getmenu();//获得菜单，并向上面添加菜单
    connect(menu, SIGNAL(triggered(QAction *)),this,SLOT(slot_clicked(QAction *)));
    connect(ui->tableWidget_66, SIGNAL(cellChanged(int,int)), this, SLOT(checkBoxChange(int, int)));
    action1 = menu->addAction("供货商管理");
    action2 = menu->addAction("商品补货");
    action3 = menu->addAction("保质期提醒");
    action4 = menu->addAction("商品类别管理");
    action5 = menu->addAction("导购员管理");
    action6 = menu->addAction("商品免税设置");

    if(LoginDialog::staffId == "cashier")
    {
        setCashierPermiss();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::slot_clicked(QAction *ev)
{
    qDebug()<<"已经点击"<<ev->text();
    if(ev = action1 )
    {
        ui->TabWidget->addTab(ui->tab_14, "供货商管理");
        ui->TabWidget->setCurrentWidget(ui->tab_14);
    }
    if(ev = action2 )
    {
        ui->TabWidget->addTab(ui->tab_15, "商品补货");
        ui->TabWidget->setCurrentWidget(ui->tab_14);
    }
    if(ev = action3 )
    {
        ui->TabWidget->addTab(ui->tab_16, "保质期提醒");
        ui->TabWidget->setCurrentWidget(ui->tab_14);
    }
    if(ev = action4 )
    {

    }
    if(ev = action5 )
    {

    }
    if(ev = action6 )
    {
        ui->TabWidget->addTab(ui->tab_14, "商品免税设置");
        ui->TabWidget->setCurrentWidget(ui->tab_17);
    }
}
//主界面时间更新函数
void MainWindow::timerUpDate()
{
    QDateTime dt = QDateTime::currentDateTime();
    QString currDateTimeStr = dt.toString(" yyyy-MM-dd  当前时间: hh:mm:ss");
    ui->label_71->setText(currDateTimeStr);
}
//双击关闭按钮关闭选项卡的方法
void MainWindow::closeTab()
{
    connect(ui->TabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(removeSubTab(int)));
}
//实现键盘事件监听
void MainWindow::keyPressEvent(QKeyEvent *)
{
    if(Qt::Key_Enter && ui->lineEdit_137->hasFocus() == true)
    {

        QString productId = ui->lineEdit_137->text();
        ui->lineEdit->clear();

        discountGoodInfoList InfoList;
        InfoList.clear();
        if ( Dbsql::getDiscountGoods(productId,InfoList))
        {
            //判断是否已经存在该商品
            getLeftRecordsList();
            for(int i = 0; i < leftRecordsList.size(); i++)
            {
                if(InfoList.contains(leftRecordsList.at(i)))
                {
                    InfoList.removeOne(leftRecordsList.at(i));
                }
            }
            updateLeftList(InfoList);
        }else
        {
            qDebug() << "获取打折商品失败!";
        }
    }
}
//设置相应用户的权限
void MainWindow::setCashierPermiss()
{
    ui->tabWidget->removeTab(1);
    ui->tabWidget->removeTab(2);
    ui->tabWidget->removeTab(3);
    ui->inStoreButton->setEnabled(false);
    ui->salesReturnButton->setEnabled(false);
    ui->instoreStatisticsButton->setEnabled(false);
    ui->saleStatisticsButton->setEnabled(false);
    ui->saleAnalysisButton->setEnabled(false);
    ui->saleDetailButton->setEnabled(false);
    ui->outstoreButton->setEnabled(false);
    ui->outstoreStatisticsButton->setEnabled(false);
    ui->staffGoveButton->setEnabled(false);
}

void MainWindow::removeSubTab(int)
{
    //    qDebug() << "current index " << ui->TabWidget->currentIndex();
    ui->TabWidget->removeTab(ui->TabWidget->currentIndex());
    if(ui->TabWidget->count() <= 0)
    {
        ui->stackedWidget->setCurrentWidget(ui->page);
    }
}

//商品入库
void MainWindow::on_inStoreButton_clicked()
{
    instore *instoreui = new instore(this);
    instoreui->show();
    instoreui->setcurrenttime();
    instoreui->exec();
}
//中间的部件重设大小
void MainWindow::resizeEvent(QResizeEvent *)
{
    ui->mainWidget->resize(this->width(),this->height()-150);

    update();
}

void MainWindow::updateLeftList(discountGoodInfoList InfoList)
{
    int j =  ui->tableWidget_66->rowCount();

    if(InfoList.size() > 0){
        ui->tableWidget_66->insertRow(j);//在第j行添加一行
    }
    for ( int i = 0; i < InfoList.size(); i++ )
    {
        QTableWidgetItem *checkBox = new QTableWidgetItem();
        checkBox->setCheckState(Qt::Checked);
        QTableWidgetItem *productIdItem = new QTableWidgetItem(InfoList.at(i).getProductId());
        QTableWidgetItem *productNameItem = new QTableWidgetItem(InfoList.at(i).getProductName());
        QTableWidgetItem *creditItem = new QTableWidgetItem(InfoList.at(i).getCredits());

        ui->tableWidget_66->setItem(j, 0, checkBox);
        ui->tableWidget_66->setItem(j, 1, productIdItem);
        ui->tableWidget_66->setItem(j, 2, productNameItem);
        ui->tableWidget_66->setItem(j, 3, creditItem);

        //字体全部中间
        productIdItem->setTextAlignment(Qt::AlignCenter);
        productNameItem->setTextAlignment(Qt::AlignCenter);
        creditItem->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget_66->setFont(QFont("宋体",9));
        ui->tableWidget_66->setSelectionBehavior(QTableWidget::SelectRows);//一次选中一行
        ui->tableWidget_66->setEditTriggers(QTableWidget::NoEditTriggers);//不能编辑
        j++;
    }
}
//得到左边被选中记录的列表
void MainWindow::getLeftSelectedRecordsList()
{
    selectedLeftRecordsList.clear();
    int rowCount = ui->tableWidget_66->rowCount();
    DiscountGoodInfo discountGoodInfo;

    for(int i = 0; i < rowCount; i++)
    {
        if(ui->tableWidget_66->item(i, 0)->checkState() == Qt::Checked) //选中
        {
            QString productId;
            QString productName;
            QString credit;

            QTableWidgetItem *productIdItem = ui->tableWidget_66->item(i,1);
            QTableWidgetItem *productNameItem = ui->tableWidget_66->item(i,2);
            QTableWidgetItem *creditItem = ui->tableWidget_66->item(i,3);

            productId = productIdItem->text();
            productName = productNameItem->text();
            credit = creditItem->text();

            discountGoodInfo.setProductId(productId);
            discountGoodInfo.setProductName(productName);
            discountGoodInfo.setCredits(credit);

            selectedLeftRecordsList.append(discountGoodInfo);
        }
    }
}
//得到左边记录的列表
void MainWindow::getLeftRecordsList()
{
    leftRecordsList.clear();
    int rowCount = ui->tableWidget_66->rowCount();
    DiscountGoodInfo discountGoodInfo;

    for(int i = 0; i < rowCount; i++)
    {
        QString productId;
        QString productName;
        QString credit;

        QTableWidgetItem *productIdItem = ui->tableWidget_66->item(i,1);
        QTableWidgetItem *productNameItem = ui->tableWidget_66->item(i,2);
        QTableWidgetItem *creditItem = ui->tableWidget_66->item(i,3);

        productId = productIdItem->text();
        productName = productNameItem->text();
        credit = creditItem->text();

        discountGoodInfo.setProductId(productId);
        discountGoodInfo.setProductName(productName);
        discountGoodInfo.setCredits(credit);

        leftRecordsList.append(discountGoodInfo);
    }
}

void MainWindow::getRightSelectedRecordsList()
{
    selectedRightRecordsList.clear();
    int rowCount = ui->tableWidget_66->rowCount();
    DiscountGoodInfo discountGoodInfo;

    for(int i = 0; i < rowCount; i++)
    {
        if(ui->tableWidget_66->item(i, 0)->checkState() == Qt::Checked) //选中
        {
            QString productId;
            QString productName;
            QString credit;

            QTableWidgetItem *productIdItem = ui->tableWidget_66->item(i,1);
            QTableWidgetItem *productNameItem = ui->tableWidget_66->item(i,2);
            QTableWidgetItem *creditItem = ui->tableWidget_66->item(i,3);

            productId = productIdItem->text();
            productName = productNameItem->text();
            credit = creditItem->text();

            discountGoodInfo.setProductId(productId);
            discountGoodInfo.setProductName(productName);
            discountGoodInfo.setCredits(credit);

            selectedRightRecordsList.append(discountGoodInfo);
        }
    }
}

void MainWindow::getRightRecordsList()
{
    rightRecordsList.clear();
    int rowCount = ui->tableWidget_67->rowCount();
    DiscountGoodInfo discountGoodInfo;

    for(int i = 0; i < rowCount; i++)
    {
        QString productId;
        QString productName;
        QString credit;

        QTableWidgetItem *productIdItem = ui->tableWidget_67->item(i,1);
        QTableWidgetItem *productNameItem = ui->tableWidget_67->item(i,2);
        QTableWidgetItem *creditItem = ui->tableWidget_67->item(i,3);

        productId = productIdItem->text();
        productName = productNameItem->text();
        credit = creditItem->text();

        discountGoodInfo.setProductId(productId);
        discountGoodInfo.setProductName(productName);
        discountGoodInfo.setCredits(credit);

        rightRecordsList.append(discountGoodInfo);
    }
}
//收银台
void MainWindow::on_checkoutButton_clicked()
{
    if ( checkoutui == NULL )
    {
        checkoutui = new PosDialog(this);
    }
    checkoutui->setSerialNumber();
    checkoutui->show();
    checkoutui->exec();
    checkoutui->clearAll();
}
//商品浏览
void MainWindow::on_scanButton_clicked()
{
    ui->TabWidget->addTab(ui->tab_5, "商品浏览");
    //当前的选项卡
    ui->TabWidget->setCurrentWidget(ui->tab_5);
    ui->stackedWidget->setCurrentWidget(ui->page_2);

    Store *store = new Store;
    store->get_store_Num();

    ProductScanInfoList ProductScanList;
    ProductScanList.clear();
    if ( Dbsql::getProduct_ScanList(ProductScanList) )
    {
        m_list = ProductScanList;

        ui->tableWidget->setRowCount(ProductScanList.size());
        for ( int i = 0; i < ProductScanList.size(); i++ )
        {
            QTableWidgetItem *classesItem = new QTableWidgetItem(m_list.at(i).classes());
            QTableWidgetItem *productIdItem = new QTableWidgetItem(m_list.at(i).productId());
            QTableWidgetItem *productNameItem = new QTableWidgetItem(m_list.at(i).productName());
            QTableWidgetItem *unitItem = new QTableWidgetItem(m_list.at(i).unit());
            QTableWidgetItem *itemNumItem = new QTableWidgetItem(m_list.at(i).itemNum());
            QTableWidgetItem *qualificationItem = new QTableWidgetItem(m_list.at(i).qualification());
            QTableWidgetItem *brandItem = new QTableWidgetItem(m_list.at(i).brand());
            ui->tableWidget->setItem(i, 0, classesItem);
            ui->tableWidget->setItem(i, 1, productIdItem);
            ui->tableWidget->setItem(i, 2, productNameItem);
            ui->tableWidget->setItem(i, 3, unitItem);
            ui->tableWidget->setItem(i, 4, qualificationItem);
            ui->tableWidget->setItem(i, 5, itemNumItem);
            ui->tableWidget->setItem(i, 6, brandItem);

            QTableWidgetItem *instoreNumItem = new QTableWidgetItem(m_list.at(i).instoreNum());
            QTableWidgetItem *purchasePriceItem = new QTableWidgetItem(m_list.at(i).purchasePrice());
            QTableWidgetItem *retailPriceItem = new QTableWidgetItem(m_list.at(i).retailPrice());
            QTableWidgetItem *memberPriceItem = new QTableWidgetItem(m_list.at(i).memberPrice());

            QTableWidgetItem *creditSchemeItem = new QTableWidgetItem(m_list.at(i).creditScheme());
            QTableWidgetItem *conversionItem = new QTableWidgetItem(m_list.at(i).conversion());
            QTableWidgetItem *discountSchemeItem = new QTableWidgetItem(m_list.at(i).discountScheme());
            QTableWidgetItem *supplyNameItem = new QTableWidgetItem(m_list.at(i).supplyName());

            QTableWidgetItem *warningNumItem = new QTableWidgetItem(m_list.at(i).warningNum());
            QTableWidgetItem *productDateItem = new QTableWidgetItem(m_list.at(i).productDate());
            QTableWidgetItem *lifeDateItem = new QTableWidgetItem(m_list.at(i).lifeDate());
            QTableWidgetItem *warningDateItem = new QTableWidgetItem(m_list.at(i).warningDate());
            QTableWidgetItem *batchNumItem = new QTableWidgetItem(m_list.at(i).batchNum());

            ui->tableWidget->setItem(i, 7, instoreNumItem);
            ui->tableWidget->setItem(i, 8, purchasePriceItem);
            ui->tableWidget->setItem(i, 9, retailPriceItem);
            ui->tableWidget->setItem(i, 10, memberPriceItem);

            ui->tableWidget->setItem(i, 11, creditSchemeItem);
            ui->tableWidget->setItem(i, 12, conversionItem);
            ui->tableWidget->setItem(i, 13, discountSchemeItem);
            ui->tableWidget->setItem(i, 14, supplyNameItem);

            ui->tableWidget->setItem(i, 15, warningNumItem);
            ui->tableWidget->setItem(i, 16, productDateItem);
            ui->tableWidget->setItem(i, 17, lifeDateItem);
            ui->tableWidget->setItem(i, 18, warningDateItem);
            ui->tableWidget->setItem(i, 19, batchNumItem);

//            QTableWidgetItem *saleNumItem = new QTableWidgetItem(m_list.at(i).saleNum());
//            QTableWidgetItem *retailPriceItem = new QTableWidgetItem(m_list.at(i).retailPrice());
//            QTableWidgetItem *profitItem = new QTableWidgetItem(m_list.at(i).profit());
//            QTableWidgetItem *profitRateItem = new QTableWidgetItem(m_list.at(i).profitRate());

//            ui->tableWidget->setItem(i, 15, saleNumItem);
//            ui->tableWidget->setItem(i, 16, retailPriceItem);
//            ui->tableWidget->setItem(i, 18, profitItem);
//            ui->tableWidget->setItem(i, 19, profitRateItem);

//            QTableWidgetItem *outstoreNumItem = new QTableWidgetItem(m_list.at(i).outstoreNum());
//            ui->tableWidget->setItem(i, 20, outstoreNumItem);

//          字体全部中间
            classesItem->setTextAlignment(Qt::AlignCenter);
            productIdItem->setTextAlignment(Qt::AlignCenter);
            productNameItem->setTextAlignment(Qt::AlignCenter);
            unitItem->setTextAlignment(Qt::AlignCenter);
            itemNumItem->setTextAlignment(Qt::AlignCenter);
            qualificationItem->setTextAlignment(Qt::AlignCenter);
            brandItem->setTextAlignment(Qt::AlignCenter);
            instoreNumItem->setTextAlignment(Qt::AlignCenter);
            purchasePriceItem->setTextAlignment(Qt::AlignCenter);
            retailPriceItem->setTextAlignment(Qt::AlignCenter);
            productDateItem->setTextAlignment(Qt::AlignCenter);
            lifeDateItem->setTextAlignment(Qt::AlignCenter);
            warningDateItem->setTextAlignment(Qt::AlignCenter);

            ui->tableWidget->setFont(QFont("宋体",9));
            ui->tableWidget->setSelectionBehavior(QTableWidget::SelectRows);//一次选中一行
            ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);//不能编辑
        }
    }else
    {
        qDebug() << "获取商品浏览列表失败!";
    }
}
//销售退货
void MainWindow::on_salesReturnButton_clicked()
{
    returnstore *returnui = new returnstore(this);
    returnui->setFixedSize(853,468);//固定大小，用户不能改变
    returnui->exec();
}
//入库统计
void MainWindow::on_instoreStatisticsButton_clicked()
{

}
//销售统计
void MainWindow::on_saleStatisticsButton_clicked()
{

}

//销售明细
void MainWindow::on_saleDetailButton_clicked()
{


}
//出库
void MainWindow::on_outstoreButton_clicked()
{
    outstore *outstoreui = new outstore;
    //    outstoreui->setFixedSize(853,468);//固定大小，用户不能改变
    outstoreui->setcurrenttime();
    outstoreui->exec();
}
//出库统计
void MainWindow::on_outstoreStatisticsButton_clicked()
{
    ui->TabWidget->addTab(ui->tab_13, "出库统计");
    //当前的选项卡
    ui->TabWidget->setCurrentWidget(ui->tab_13);
}
//打印实现
void MainWindow::on_paintButton_clicked()
{
    doPrintPreview();
    //    createPdf();
    //    setUpPage();
    //    doPrint();
}
//打印具体
//void MainWindow::doPrint()
//{
//    // 创建打印机对象
//    QPrinter printer;
//    // 创建打印对话框
//    QString printerName = printer.printerName();
//    if( printerName.size() == 0)
//        return;
//    QPrintDialog dlg(&printer, this);
//    //如果编辑器中有选中区域，则打印选中区域
//    if (ui->tableWidget->textCursor().hasSelection())
//        dlg.addEnabledOption(QAbstractPrintDialog::PrintSelection);
//    // 如果在对话框中按下了打印按钮，则执行打印操作
//    if (dlg.exec() == QDialog::Accepted)
//    {
//        ui->tableWidget->print(&printer);
//        // print the existing document by absoult path
//        //  printFile("D:/myRSM.doc");
//    }
//}
// 打印预览
void MainWindow::doPrintPreview()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer,this);
    connect(&preview, SIGNAL(paintRequested(QPrinter *)),this,SLOT(plotPic(QPrinter *)));
    QMessageBox msgBox;
    msgBox.setText(tr("请选择打印方式"));
    msgBox.addButton(tr("输出到文档"),QMessageBox::AcceptRole);
    msgBox.addButton(tr("输出到打印机"),QMessageBox::RejectRole);
    if(msgBox.exec()==QMessageBox::AcceptRole)
        printer.setOutputFormat(QPrinter::PdfFormat);
    preview.exec();
}
void MainWindow::plotPic(QPrinter *)
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
        QWidget *myForm=new QWidget(this);
        myForm->setObjectName(QString::fromUtf8("Form"));
        myForm->resize(1072, 768);
        QTableWidget *tableWidget;
        tableWidget = new QTableWidget(myForm);
        tableWidget->setColumnCount(3);
        tableWidget->setRowCount(4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0,1072, 768));
        //        QPainter painter(&printer);
        //        painter.drawPixmap(0, 0, QPixmap::grabWidget(0,0,400,300));
        QPainter painter(&printer);
        QPixmap image;
        image=image.grabWidget(0,0,400, 300);
        QRect rect = painter.viewport();
        QSize size = image.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);     //此处保证图片显示完整
        painter.setViewport(rect.x(), rect.y(),size.width(), size.height());
        painter.setWindow(image.rect());
        painter.drawPixmap(0,0,image);
    }
}
//// 生成PDF文件
//void MainWindow::createPdf()
//{
//    QString fileName = QFileDialog::getSaveFileName(this, tr("导出PDF文件"), QString(), "*.pdf");
//    if (!fileName.isEmpty()) {
//        // 如果文件后缀为空，则默认使用.pdf
//        if (QFileInfo(fileName).suffix().isEmpty())
//            fileName.append(".pdf");
//        QPrinter printer;
//        // 指定输出格式为pdf
//        printer.setOutputFormat(QPrinter::PdfFormat);
//        printer.setOutputFileName(fileName);
//        ui->tableWidget->print(&printer);
//    }
//}
// 页面设置
//void MainWindow::setUpPage()
//{
//    QPrinter printer;
//    QPageSetupDialog pageSetUpdlg(&printer, this);
//    if (pageSetUpdlg.exec() == QDialog::Accepted)
//    {
//        printer.setOrientation(QPrinter::Landscape);
//    }
//    else
//    {
//        printer.setOrientation(QPrinter::Portrait);
//    }
//}
//导出实现
void MainWindow::on_exportButton_clicked()
{
    //    QAxObject *pApplication = NULL;
    //    QAxObject *pWorkBooks = NULL;
    //    QAxObject *pWorkBook = NULL;
    //    QAxObject *pSheets = NULL;
    //    QAxObject *pSheet = NULL;

    //    pApplication = new QAxObject();
    //    pApplication->setControl("Excel.Application");//连接Excel控件
    //    pApplication->dynamicCall("SetVisible(bool)", false);//false不显示窗体
    //    pApplication->setProperty("DisplayAlerts", false);//不显示任何警告信息。
    //    pWorkBooks = pApplication->querySubObject("Workbooks");
    //    QFile file(fileName);
    //    if (file.exists())
    //    {
    //        pWorkBook = pWorkBooks->querySubObject("Open(const QString &)", fileName);
    //    }
    //    else
    //    {
    //        pWorkBooks->dynamicCall("Add");
    //        pWorkBook = pApplication->querySubObject("ActiveWorkBook");
    //    }
    //    pSheets = pWorkBook->querySubObject("Sheets");
    //    pSheet = pSheets->querySubObject("Item(int)", 1);

    //    QAxObject *pLastSheet = pSheets->querySubObject("Item(int)", cnt);
    //    pSheets->querySubObject("Add(QVariant)", pLastSheet->asVariant());
    //    pSheet = pSheets->querySubObject("Item(int)", cnt);
    //    pLastSheet->dynamicCall("Move(QVariant)", pSheet->asVariant());
    //    pSheet->setProperty("Name", sheetName);

    //    QAxObject *pRange = pSheet->querySubObject("Cells(int,int)", row, column);
    //    range->dynamicCall("Value", value);

    //    pWorkBook->dynamicCall("SaveAs(const QString &)",
    //                           QDir::toNativeSeparators(fileName));

    //    if (pApplication != NULL)
    //    {
    //        pApplication->dynamicCall("Quit()");
    //        delete pApplication;
    //        pApplication = NULL;
    //    }
}
//帮助文档
void MainWindow::on_helpButton_clicked()
{

}
//退出软件
void MainWindow::on_outButton_clicked()
{
    this->close();
}
//会员信息
void MainWindow::on_memberButton_clicked()
{
    ui->TabWidget->addTab(ui->tab_18, "会员信息");
    //当前的选项卡
    ui->TabWidget->setCurrentWidget(ui->tab_18);

    memberInfoList memberInfoList;
    memberInfoList.clear();
    if ( Dbsql::getMember_ScanList(memberInfoList) )//有一部分写死了
    {
        ui->tableWidget_47->setRowCount(memberInfoList.size());
        for ( int i = 0; i < memberInfoList.size(); i++ )
        {
            QTableWidgetItem *memberTypeItem = new QTableWidgetItem(memberInfoList.at(i).memberType());
            QTableWidgetItem *beginCreditItem = new QTableWidgetItem(memberInfoList.at(i).beginCredit());
            QTableWidgetItem *memberIdItem = new QTableWidgetItem(memberInfoList.at(i).memberId());
            QTableWidgetItem *memberNameItem = new QTableWidgetItem(memberInfoList.at(i).memberName());

            QTableWidgetItem *birthdayItem = new QTableWidgetItem(memberInfoList.at(i).birthday());
            QTableWidgetItem *birthWarnItem = new QTableWidgetItem(memberInfoList.at(i).birthWarn());
            QTableWidgetItem *phoneNumItem = new QTableWidgetItem(memberInfoList.at(i).phoneNum());
            QTableWidgetItem *userCreditItem = new QTableWidgetItem(memberInfoList.at(i).userCredit());
            QTableWidgetItem *emailItem = new QTableWidgetItem(memberInfoList.at(i).email());

            ui->tableWidget_47->setItem(i, 0, beginCreditItem);
            ui->tableWidget_47->setItem(i, 1, memberIdItem);
            ui->tableWidget_47->setItem(i, 2, memberNameItem);
            ui->tableWidget_47->setItem(i, 3, birthdayItem);
            ui->tableWidget_47->setItem(i, 4, birthWarnItem);
            ui->tableWidget_47->setItem(i, 5, phoneNumItem);
            ui->tableWidget_47->setItem(i, 6, emailItem);
            ui->tableWidget_47->setItem(i, 7, userCreditItem);
            ui->tableWidget_47->setItem(i, 8, memberTypeItem);


            QTableWidgetItem *columnHeaderItem0 = ui->tableWidget_47->horizontalHeaderItem(0); //获得水平方向表头的Item对象
            //            columnHeaderItem0->setFont(QFont("Helvetica")); //设置字体
            columnHeaderItem0->setBackgroundColor(QColor(0,60,10)); //设置单元格背景颜色
            //            columnHeaderItem0->setTextColor(QColor(200,111,30)); //设置文字颜色

            ui->tableWidget_47->setFont(QFont("宋体",9));
            ui->tableWidget_47->setSelectionBehavior(QTableWidget::SelectRows);//一次选中一行
            ui->tableWidget_47->setEditTriggers(QTableWidget::NoEditTriggers);//不能编辑
        }
    }
}
//增加会员
void MainWindow::on_addMemberButton_clicked()
{
    addmember *addmerberui = new addmember(this);
    addmerberui->show();
    addmerberui->exec();
}
//积分历史
void MainWindow::on_creditsHistoryButton_clicked()
{

}
//消费明细
void MainWindow::on_expenseDetailButton_clicked()
{

}
//收支明细
void MainWindow::on_incomeDetailButton_clicked()
{

}
//会员充值
void MainWindow::on_memberRechangeButton_clicked()
{

}
//充值统计
void MainWindow::on_rechangeStatisticsButton_clicked()
{

}
//会员配置
void MainWindow::on_memberCnfigurationButton_clicked()
{

}
//积分设置
void MainWindow::on_creditsSetButton_clicked()
{
    ui->TabWidget->addTab(ui->tab_24, "会员信息");
    //当前的选项卡
    ui->TabWidget->setCurrentWidget(ui->tab_24);
}
//折扣设置
void MainWindow::on_discountSetButton_clicked()
{

}
//生日提醒
void MainWindow::on_birthdayButton_clicked()
{

}
//参数配置
void MainWindow::on_parameterConfigurationButton_clicked()
{

}
//修改密码
void MainWindow::on_modifyPwdButton_clicked()
{
    modifypwd *modifypwdui = new modifypwd(this);
    modifypwdui->show();
    modifypwdui->exec();
}
//用户管理
void MainWindow::on_staffGoveButton_clicked()
{

}
//数据处理
void MainWindow::on_dataMangeButton_clicked()
{

}
//导入信息
void MainWindow::on_importButton_clicked()
{

}
//备份还原
void MainWindow::on_back_upButton_clicked()
{

}
//交班结算
void MainWindow::on_exchangeButton_clicked()
{

}
//交班统计
void MainWindow::on_exchangeStatisticsButton_clicked()
{

}
//库存盘点
void MainWindow::on_modifyButton_clicked()
{

}
//盘点统计
void MainWindow::on_modifyStatisticsButton_clicked()
{

}
//商品拆装
void MainWindow::on_dismountingButton_clicked()
{

}
//其他设置
void MainWindow::on_otherSetButton_clicked()
{

}
//帮助文档
void MainWindow::on_helpButton_2_clicked()
{
    QProcess * mp_helpProcess = new QProcess(this);
    QStringList argument("help.chm");
    mp_helpProcess->start("hh.exe", argument);//运行另一个程序片段的代码
}
//购买软件
void MainWindow::on_purchaseButton_clicked()
{
    AboutDialog1 *AboutDialog1ui = new AboutDialog1;
    AboutDialog1ui->show();
}
//注册认证
void MainWindow::on_registerButton_clicked()
{
    AboutDialog2 *AboutDialog2ui = new AboutDialog2;
    AboutDialog2ui->show();
}
//官方网站
void MainWindow::on_webButton_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.baidu.com"));
}

//客户服务
void MainWindow::on_serviceButton_clicked()
{
    AboutDialog3 *AboutDialog3ui = new AboutDialog3;
    AboutDialog3ui->show();

}
//留言反馈
void MainWindow::on_QQButton_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.baidu.com"));
}
//检测更新
void MainWindow::on_updateButton_clicked()
{

}
//关于
void MainWindow::on_aboutButton_clicked()
{
    AboutDialog4 *AboutDialog4ui = new AboutDialog4;
    AboutDialog4ui->show();
}
//刷新
void MainWindow::on_refreshButton_clicked()
{
    update();
}
//左边的tableWidget中的一行被选中的操作（暂时不做）
void MainWindow::checkBoxChange(int row, int col)
{
    if(ui->tableWidget_66->item(row, col)->checkState() == Qt::Checked) //选中
    {
//        qDebug() << row << col;
    }
    else
    {

    }
}

//将左边被选中的项移到右边
void MainWindow::on_pushButton_right_clicked()
{
    getLeftSelectedRecordsList();

    //得到没有被选中的商品
    for(int i = 0; i < selectedLeftRecordsList.size();  i++)
    {
        if(leftRecordsList.contains(selectedLeftRecordsList.at(i)))
        {
            leftRecordsList.removeOne(selectedLeftRecordsList.at(i));
        }
    }
    //判断是否已经存在该商品
    getRightRecordsList();
    for(int i = 0; i < rightRecordsList.size(); i++)
    {
        if(selectedLeftRecordsList.contains(rightRecordsList.at(i)))
        {
            selectedLeftRecordsList.removeOne(rightRecordsList.at(i));
        }
    }

    int j =  ui->tableWidget_67->rowCount();

    for ( int i = 0; i < selectedLeftRecordsList.size(); i++ )
    {
        ui->tableWidget_67->insertRow(j);//在第j行添加一行

        QTableWidgetItem *checkBox1 = new QTableWidgetItem();
        checkBox1->setCheckState(Qt::Checked);
        QTableWidgetItem *productIdItem = new QTableWidgetItem(selectedLeftRecordsList.at(i).getProductId());
        QTableWidgetItem *productNameItem = new QTableWidgetItem(selectedLeftRecordsList.at(i).getProductName());
        QTableWidgetItem *creditItem = new QTableWidgetItem(selectedLeftRecordsList.at(i).getCredits());
        QTableWidgetItem *checkBox2 = new QTableWidgetItem();
        checkBox2->setCheckState(Qt::Checked);

        ui->tableWidget_67->setItem(j, 0, checkBox1);
        ui->tableWidget_67->setItem(j, 1, productIdItem);
        ui->tableWidget_67->setItem(j, 2, productNameItem);
        ui->tableWidget_67->setItem(j, 3, creditItem);
        ui->tableWidget_67->setItem(j, 4, checkBox2);

        //字体全部中间
        productIdItem->setTextAlignment(Qt::AlignCenter);
        productNameItem->setTextAlignment(Qt::AlignCenter);
        creditItem->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget_67->setFont(QFont("宋体",9));
        ui->tableWidget_67->setSelectionBehavior(QTableWidget::SelectRows);//一次选中一行
        ui->tableWidget_67->setEditTriggers(QTableWidget::NoEditTriggers);//不能编辑
        j++;
    }

    //更新左边的列表
    ui->tableWidget_66->clearContents();
    ui->tableWidget_66->setRowCount(0);
    qDebug() << leftRecordsList.size();
    updateLeftList(leftRecordsList);
}
