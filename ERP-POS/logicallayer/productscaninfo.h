#ifndef PRODUCTSCANINFO_H
#define PRODUCTSCANINFO_H

#include "producttype.h"
#include "supplyinfo.h"
#include "saleinfo.h"
#include "outstoreinfo.h"
#include "instoreinfo.h"
#include "storeinfo.h"

class ProductScanInfo : public ProductType, public SupplyInfo,
        public InstoreInfo, public saleInfo, public outStoreInfo,public storeInfo
{

public:
    ProductScanInfo();

    ProductScanInfo(const ProductScanInfo &other )
        :ProductType(other),
          SupplyInfo(other),
          InstoreInfo(other),
          saleInfo(other),
          outStoreInfo(other),
          storeInfo(other)
    {

    }
    ProductScanInfo operator = (const ProductScanInfo &other)
    {
        ProductType::operator =(other);
        SupplyInfo::operator =(other);
        InstoreInfo::operator =(other);
        saleInfo::operator =(other);
        outStoreInfo::operator =(other);
        storeInfo::operator =(other);
    }

    ProductScanInfo(const QString &producyId, const QString &productName,
                    const QString &unit, const QString &classes,const QString &qualification,
                    const QString &itemNum, const QString &brand, const QString &purchasePrice,
                    const QString &retailPrice, const QString &memberPrice, const QString &creditScheme,
                    const QString &conversion, const QString &discountScheme, const QString &warningNum,
                    const QString &productDate, const QString &lifeDate, const QString &warningDate,
                    const QString &batchNum, const QString &remarks,
                    const QString &suppId, const QString &suppName,
                    const QString instoreDate,const QString &instoreNum,
                    const QString &saleDate, const QString &serialNumber,
                    const QString &saleNum, const QString &profit,
                    const QString &profitRate,const QString &saleSum, const QString &salenumSum,const QString &purchaseSum, const QString &discountSum,
                    const QString &favorableSum, const QString &profitSum,
                    const QString &shouldreceive, const QString &reallyreceive, const QString &change,
                    const QString &outstoreprice, const QString &outstoreNum,
                    const QString &Number)
        :ProductType(producyId,productName,unit,classes,qualification,itemNum,brand,purchasePrice,
                     retailPrice,memberPrice,creditScheme,conversion,discountScheme,warningNum,
                     productDate,lifeDate,warningDate,batchNum,remarks),
          SupplyInfo(suppId,suppName),
          InstoreInfo(instoreDate,instoreNum),
          saleInfo(saleDate,serialNumber,saleNum,profit,
                   profitRate,salenumSum,saleSum,purchaseSum,discountSum,
                   favorableSum,profitSum,shouldreceive,reallyreceive,change),
          outStoreInfo(outstoreprice,outstoreNum),
          storeInfo(Number)
    {}
};

typedef QList<ProductScanInfo> ProductScanInfoList;

#endif // PRODUCTSCANINFO_H
