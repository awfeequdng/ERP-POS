#ifndef SALEANALYSIS_H
#define SALEANALYSIS_H

#include <producttype.h>
#include <saleinfo.h>
#include <supplyinfo.h>
#include <staffinfo.h>

class SaleAnalysis: public ProductType, public SupplyInfo,
        public saleInfo, public staffInfo
{
public:
    SaleAnalysis();

    SaleAnalysis( const SaleAnalysis &other )
        :ProductType(other),
          SupplyInfo(other),
          saleInfo(other),
          staffInfo(other)
    {
    }

    SaleAnalysis(const QString &productId, const QString &productName,
                 const QString &unit, const QString &classes,const QString &qualification,
                 const QString &itemNum, const QString &brand, const QString &purchasePrice,
                 const QString &retailPrice, const QString &memberPrice, const QString &creditScheme,
                 const QString &conversion, const QString &discountScheme, const QString &warningNum,
                 const QString &productDate, const QString &lifeDate, const QString &warningDate,
                 const QString &batchNum, const QString &remarks,
                 const QString &supplyId, const QString &supplyname,
                 const QString &saleDate, const QString &serialNumber, const QString &saleNum,
                 const QString &profit, const QString &profitRate, const QString &salenumSum,
                 const QString &saleSum, const QString &purchaseSum, const QString &discountSum,
                 const QString &favorableSum, const QString &profitSum, const QString &shouldreceive, const QString &reallyreceive, const QString &change,
                 const QString &staffId,const QString &staffName
                 )
        :ProductType(productId,productName,unit,classes,qualification,itemNum,brand,purchasePrice,
                     retailPrice,memberPrice,creditScheme,conversion,discountScheme,warningNum,
                     productDate,lifeDate,warningDate,batchNum,remarks),
          SupplyInfo(supplyId,supplyname),
          saleInfo(saleDate,serialNumber,saleNum,profit,profitRate,salenumSum,saleSum,purchaseSum,discountSum,favorableSum,profitSum,shouldreceive,reallyreceive,change),
          staffInfo(staffId,staffName)
    {}
};
typedef QList<SaleAnalysis> SaleAnalysisList;


#endif // SALEANALYSIS_H
