#ifndef DBSQL_H
#define DBSQL_H

#include "productscaninfo.h"
#include "instoreanalysis.h"
#include "saledetail.h"
#include "saleanalysis.h"
#include "memberinfo.h"
#include "discountgoodinfo.h"

class Dbsql
{
public:
    Dbsql();

    static bool getProduct_ScanList(ProductScanInfoList &ProductScanInfoList );

    static bool getInstore_AnalysisList(InstoreAnalysisList &InstoreAnalysisList );

    static bool getSale_AnalysisList(SaleAnalysisList &SaleAnalysisList );

    static bool getSale_DetailList(SaleDetailList &SaleDetailList);

    static bool getMember_ScanList(memberInfoList &memberInfoList);

    static bool getDiscountGoods(QString conditions, discountGoodInfoList &discountGoodInfoList);
};

#endif // DBSQL_H
