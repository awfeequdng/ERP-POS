#include "dbsql.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QDebug>

#include "productscaninfo.h"
#include "instoreanalysis.h"
#include "saledetail.h"/*销售明细*/
#include "saleanalysis.h"/*销售统计*/

Dbsql::Dbsql()
{

}

bool Dbsql::getProduct_ScanList(ProductScanInfoList &ProductScanInfoList)
{
    QSqlQuery query;
    QString querystring = QString("select * from product_scan");
    ProductScanInfo info;
    if ( query.exec(querystring) )
    {
        while ( query.next() )
        {
            info.setClasses(query.value(0).toString());
            info.setProductId(query.value(1).toString());
            info.setProductName(query.value(2).toString());
            info.setUnit(query.value(3).toString());
            info.setItemNum(query.value(4).toString());
            info.setQualification(query.value(5).toString());
            info.setBrand(query.value(6).toString());
            info.setPurchasePrice(query.value(7).toString());
            info.setRetailPrice(query.value(8).toString());
            info.setMemberPrice(query.value(9).toString());

            info.setInstoreNum(query.value(10).toString());
            info.setWarningNum(query.value(11).toString());
            info.setConversion(query.value(12).toString());
            info.setCreditScheme(query.value(13).toString());
            info.setDiscountScheme(query.value(14).toString());
            info.setSupplyName(query.value(15).toString());
            info.setProductDate(query.value(16).toString());
            info.setLifeDate(query.value(17).toString());
            info.setWarningDate(query.value(18).toString());
            info.setBatchNum(query.value(19).toString());

            ProductScanInfoList.append(info);
        }
    }
    else
    {
        qDebug() << "getSingleModeInfoList Error";
        return false;
    }

    qDebug() << "query success ";
    return true;
}

bool Dbsql::getInstore_AnalysisList(InstoreAnalysisList &InstoreAnalysisList)
{
    QSqlQuery query;
    QString querystring2 = QString("select * from instore");
    InstoreAnalysis info;
    //     qDebug() << "search product scan 1";
    if ( query.exec(querystring2) )
    {
        //         qDebug() << "search product scan2";
        while ( query.next() )
        {
            //                qDebug() << "search product scan";

            info.setInstoreDate(query.value(0).toString());
            //               qDebug() << "date info " << query.value(0).toString();
            info.setClasses(query.value(6).toString());
            info.setProductId(query.value(1).toString());
            info.setProductName(query.value(2).toString());
            info.setUnit(query.value(3).toString());
            info.setQualification(query.value(5).toString());
            info.setItemNum(query.value(4).toString());
            info.setPurchasePrice(query.value(7).toString());
            info.setInstoreNum(query.value(11).toString());
            info.setRetailPrice(query.value(8).toString());

            info.setProductDate(query.value(15).toString());
            info.setLifeDate(query.value(16).toString());
            info.setWarningDate(query.value(17).toString());
            info.setBatchNum(query.value(18).toString());
            info.setSupplyName(query.value(13).toString());
            info.setRemarks(query.value(23).toString());
            //                qDebug() << query.value(0).toString() << " : "
            //                         << query.value(1).toString();

            InstoreAnalysisList.append(info);
        }
    }
    else
    {
        qDebug() << "getSingleModeInfoList Error";
        return false;
    }

    qDebug() << "query success ";
    return true;
}

bool Dbsql::getSale_AnalysisList(SaleAnalysisList &SaleAnalysisList)
{
    QSqlQuery query;
    QString querystring4 = QString("select * from saledetail;");
    SaleAnalysis info;

    if ( query.exec(querystring4) )
    {
        while ( query.next() )
        {
            info.setSaleDate(query.value(0).toString());
            info.setSerialNumber(query.value(1).toString());

            info.setStaffName(query.value(3).toString());
            info.setProductId(query.value(4).toString());
            info.setProductName(query.value(5).toString());

            info.setSalenumSum(query.value(28).toString());
            info.setSaleSum(query.value(29).toString());
            info.setDiscountSum(query.value(31).toString());
            info.setFavorableSum(query.value(32).toString());
            info.setProfitSum(query.value(33).toString());

            info.setShouldreceive(query.value(24).toString());
            info.setReallyreceive(query.value(25).toString());
            info.setChange(query.value(26).toString());

            //                qDebug() << query.value(0).toString() << " : "
            //                         << query.value(1).toString();
            SaleAnalysisList.append(info);
        }
    }
    else
    {
        qDebug() << "SaleAnalysisList Error";
        return false;
    }

    qDebug() << "query success ";
    return true;

}

bool Dbsql::getSale_DetailList(SaleDetailList &SaleDetailList)
{
    QSqlQuery query;
    QString querystring3 = QString("select * from saleDetail;");
    SaleDetail info;
    qDebug() << "search sale detail ";
    if ( query.exec( querystring3 ) )
    {
        while ( query.next() )
        {
            info.setSaleDate(query.value(0).toString());
            info.setSerialNumber(query.value(1).toString());

            info.setStaffName(query.value(2).toString());
            info.setProductId(query.value(3).toString());
            info.setProductName(query.value(4).toString());
            info.setSaleNum(query.value(5).toString());
            info.setRetailPrice(query.value(6).toString());


            info.setPurchasePrice(query.value(11).toString());
            info.setProfit(query.value(12).toString());
            info.setProfitRate(query.value(13).toString());

            info.setClasses(query.value(15).toString());
            info.setQualification(query.value(14).toString());
            info.setItemNum(query.value(16).toString());
            info.setBrand(query.value(17).toString());

            info.setProductDate(query.value(19).toString());
            info.setLifeDate(query.value(20).toString());
            info.setWarningDate(query.value(21).toString());
            info.setBatchNum(query.value(16).toString());
            info.setSupplyName(query.value(12).toString());
            info.setRemarks(query.value(13).toString());
            qDebug() << query.value(0).toString() << " : "
                     << query.value(1).toString();

            SaleDetailList.append(info);
        }
    }
    else
    {
        qDebug() << "getSaleDetailList Error";
        return false;
    }

    qDebug() << "query success ";
    return true;
}

bool Dbsql::getMember_ScanList(memberInfoList &memberInfoList)
{
    QSqlQuery query;
    QString querystring = QString("select * from memberInfo;");
    memberInfo info;
    qDebug() << "search memberInfo ";

    if ( query.exec( querystring ) )
    {
        while ( query.next() )
        {
            info.setMemberId(query.value(0).toString());
            info.setMemberType(query.value(1).toString());
            info.setMemberName(query.value(2).toString());
            info.setBeginCredit(query.value(3).toString());
            info.setUserCredit(query.value(4).toString());
            info.setBirthday(query.value(7).toString());
            info.setBirthWarn(query.value(8).toString());
            info.setPhoneNum(query.value(9).toString());
            info.setEmail(query.value(11).toString());

            qDebug() << query.value(0).toString() << " : "
                     << query.value(1).toString();

            memberInfoList.append(info);
        }
    }
    else
    {
        qDebug() << "getMember_ScanList Error";
        return false;
    }

    qDebug() << "query success ";
    return true;
}

bool Dbsql::getDiscountGoods(QString value, discountGoodInfoList &discountGoodInfoList)
{
    QSqlQuery query;
    QString querystring = QString("select productId,productName,credits from productInfo where productId = '"+value+"';");
    DiscountGoodInfo discountGoodInfo;

    if ( query.exec( querystring ) )
    {
        while ( query.next() )
        {
            discountGoodInfo.setProductId(query.value(0).toString());
            discountGoodInfo.setProductName(query.value(1).toString());
            discountGoodInfo.setCredits(query.value(2).toString());

            discountGoodInfoList.append(discountGoodInfo);
        }
    }
    else
    {
        qDebug() << "getDiscountGoods Error";
        return false;
    }

    qDebug() << "query success ";
    return true;
}
