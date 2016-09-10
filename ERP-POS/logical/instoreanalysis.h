#ifndef INSTOREANALYSIS_H
#define INSTOREANALYSIS_H

#include <QList>
#include "instoreinfo.h"
#include "producttype.h"
#include "instoreinfo.h"
#include "supplyinfo.h"

class InstoreAnalysis : public ProductType, public InstoreInfo, public SupplyInfo
{
public:
    InstoreAnalysis();

    InstoreAnalysis( const InstoreAnalysis &other )
        :ProductType(other),
          InstoreInfo(other),
          SupplyInfo(other)
    {

    }

    InstoreAnalysis operator = (const InstoreAnalysis &other)
    {
        ProductType::operator =(other);
        InstoreInfo::operator =(other);
        SupplyInfo::operator =(other);
    }


    InstoreAnalysis(const QString &producyId, const QString &productName,
                    const QString &unit, const QString &classes,const QString &qualification,
                    const QString &itemNum, const QString &brand, const QString &purchasePrice,
                    const QString &retailPrice, const QString &memberPrice, const QString &creditScheme,
                    const QString &conversion, const QString &discountScheme, const QString &warningNum,
                    const QString &productDate, const QString &lifeDate, const QString &warningDate,
                    const QString &batchNum, const QString &remarks,
                    const QString &supplyId, const QString &supplyname,
                    const QString &instoreDate,const QString &instoreNum
                    )
        :ProductType(producyId,productName,unit,classes,qualification,itemNum,brand,purchasePrice,
                     retailPrice,memberPrice,creditScheme,conversion,discountScheme,warningNum,
                     productDate,lifeDate,warningDate,batchNum,remarks),
          InstoreInfo(instoreDate,instoreNum),
          SupplyInfo(supplyId,supplyname)
    {}
};
typedef QList<InstoreAnalysis> InstoreAnalysisList;

#endif // INSTOREANALYSIS_H
