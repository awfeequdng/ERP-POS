#include "store.h"
#include "instore.h"
#include "outstore.h"
#include "PosDialog.h"
#include "returnstore.h"

#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QMessageBox>

Store::Store()
{

}
void Store::get_store_Num()
{

    QString queryinstore = "select instoreNum,productId from instore;";
    QString querysale = "select saleNum from sales where productId = (select productId from instore;)";
    QString queryoutstore = "select outstoreNum from outstore where productId = (select productId from instore);";
    QString queryreturnstore = "select returnNum from returnstore where productId = (select productId from instore);";
    QString productId;
    QString instoreNum;
    QString saleNum;
    QString outstoreNum;
    QString returnstore;
    double storeNum;
    QSqlQuery query;

    if(query.exec(queryinstore))
    {
        while(query.next())
        {
            productId = query.value(0).toString();
            instoreNum = query.value(1).toString();
        }
    }
    if( query.exec(querysale))
    {
        while(query.next())
        {
            saleNum = query.value(1).toString();
        }
    }

    if(query.exec(queryoutstore))
    {
        while(query.next())
        {
            outstoreNum = query.value(1).toString();
        }
    }

    if(query.exec(queryreturnstore))
    {
        while(query.next())
        {
            returnstore = query.value(1).toString();
        }
    }

    storeNum = instoreNum.toDouble()- saleNum.toDouble() - outstoreNum.toDouble() + returnstore.toDouble();

    QString str = QString("INSERT INTO store (Number) values('%1') where productId = (select productId from instore) ;").arg(storeNum);

    if(query.exec(str))
    {}else
    {
//       QMessageBox::text("库存金额错误");
    }
//    qDebug()<<QString::number(storeNum);
//    qDebug()<<instoreNum.toDouble();
//    qDebug()<<saleNum.toDouble();
}


