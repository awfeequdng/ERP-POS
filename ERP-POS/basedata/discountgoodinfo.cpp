#include "discountgoodinfo.h"

DiscountGoodInfo::DiscountGoodInfo()
{

}
QString DiscountGoodInfo::getProductId() const
{
    return productId;
}

void DiscountGoodInfo::setProductId(const QString &value)
{
    productId = value;
}
QString DiscountGoodInfo::getProductName() const
{
    return productName;
}

void DiscountGoodInfo::setProductName(const QString &value)
{
    productName = value;
}
QString DiscountGoodInfo::getCredits() const
{
    return credits;
}

void DiscountGoodInfo::setCredits(const QString &value)
{
    credits = value;
}

bool DiscountGoodInfo::operator ==(const DiscountGoodInfo &other)
{
    if ( this->productId == other.productId )
        return true;

    return false;
}



