#ifndef SALEDETAIL_H
#define SALEDETAIL_H

#include <producttype.h>
#include <saleinfo.h>
#include <supplyinfo.h>
#include <staffinfo.h>

class SaleDetail : public ProductType, public SupplyInfo,
         public saleInfo,public staffInfo
{
public:
    SaleDetail();

    SaleDetail( const SaleDetail &other )
        :ProductType(other),
          saleInfo(other),
          SupplyInfo(other),
          staffInfo(other)
    {
    }

    SaleDetail operator = (const SaleDetail &other)
    {
        ProductType::operator =(other);
        saleInfo::operator =(other);
        SupplyInfo::operator =(other);
        staffInfo::operator =(other);
    }

    SaleDetail(const QString &productId, const QString &productName,
               const QString &unit, const QString &classes,const QString &qualification,
               const QString &itemNum, const QString &brand, const QString &purchasePrice,
               const QString &retailPrice, const QString &memberPrice, const QString &creditScheme,
               const QString &conversion, const QString &discountScheme, const QString &warningNum,
               const QString &productDate, const QString &lifeDate, const QString &warningDate,
               const QString &batchNum, const QString &remarks,
               const QString &supplyId, const QString &supplyname,
               const QString &saleDate, const QString &serialNumber,
               const QString &saleNum, const QString &profit,
               const QString &profitRate,const QString &saleSum, const QString &salenumSum,
               const QString &purchaseSum, const QString &discountSum,
               const QString &favorableSum, const QString &profitSum,
               const QString &shouldreceive, const QString &reallyreceive, const QString &change,
               const QString &staffId,const QString &staffName
                    )
        :ProductType(productId,productName,unit,classes,qualification,itemNum,brand,purchasePrice,
                     retailPrice,memberPrice,creditScheme,conversion,discountScheme,warningNum,
                     productDate,lifeDate,warningDate,batchNum,remarks),
          saleInfo(saleDate,serialNumber,saleNum,profit,profitRate,salenumSum,saleSum,
                   purchaseSum,discountSum,favorableSum,profitSum,shouldreceive,
                   reallyreceive,change),
          SupplyInfo(supplyId,supplyname),
          staffInfo(staffId,staffName)
            {}
};

typedef QList<SaleDetail> SaleDetailList;

#endif // SALEDETAIL_H
