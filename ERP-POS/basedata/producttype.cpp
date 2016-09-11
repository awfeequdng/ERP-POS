#include "producttype.h"

ProductType::ProductType()
{
}

ProductType::ProductType(const ProductType &other)
{
    this->m_productId = other.m_productId;
    this->m_productName = other.m_productName;
    this->m_unit = other.m_unit;
    this->m_classes = other.m_classes;
    this->m_qualification = other.m_qualification;
    this->m_itemNum = other.m_itemNum;
    this->m_brand = other.m_brand;
    this->m_purchasePrice = other.m_purchasePrice;
    this->m_retailPrice = other.m_retailPrice;
    this->m_memberPrice = other.m_memberPrice;
    this->m_creditScheme = other.m_creditScheme;
    this->m_conversion = other.m_conversion;
    this->m_discountScheme = other.m_discountScheme;
    this->m_warningNum = other.m_warningNum;
    this->m_productDate = other.m_productDate;
    this->m_lifeDate = other.m_lifeDate;
    this->m_warningDate = other.m_warningDate;
    this->m_batchNum = other.m_batchNum;
    this->m_remarks = other.m_remarks;
}

ProductType ProductType::operator =(const ProductType &other )
{
    if ( this == &other )
        return *this;
    this->m_productId = other.m_productId;
    this->m_productName = other.m_productName;
    this->m_unit = other.m_unit;
    this->m_classes = other.m_classes;
    this->m_qualification = other.m_qualification;
    this->m_itemNum = other.m_itemNum;
    this->m_brand = other.m_brand;
    this->m_purchasePrice = other.m_purchasePrice;
    this->m_retailPrice = other.m_retailPrice;
    this->m_memberPrice = other.m_memberPrice;
    this->m_creditScheme = other.m_creditScheme;
    this->m_conversion = other.m_conversion;
    this->m_discountScheme = other.m_discountScheme;
    this->m_warningNum = other.m_warningNum;
    this->m_productDate = other.m_productDate;
    this->m_lifeDate = other.m_lifeDate;
    this->m_warningDate = other.m_warningDate;
    this->m_batchNum = other.m_batchNum;
    this->m_remarks = other.m_remarks;
    return *this;
}

//构造
bool ProductType::operator ==(const ProductType &other)
{
    if ( this->m_productId == other.m_productId )
        return true;

    return false;
}
//<构造
bool ProductType::operator <(const ProductType &other)
{
    if ( this->m_productId < other.m_productId )
        return true;

    return false;
}

ProductType::ProductType(const QString &id, const QString &name,const QString &unit, const QString &classes,const QString &qualification,
                         const QString &itemNum, const QString &brand, const QString &purchasePrice,
                         const QString &retailPrice, const QString &memberPrice, const QString &creditScheme,
                         const QString &conversion, const QString &discountScheme, const QString &warningNum,
                         const QString &productDate, const QString &lifeDate, const QString &warningDate,
                         const QString &batchNum, const QString &remarks)
{
    m_productId = id;
    m_productName = name;
    m_unit = unit;
    m_classes = classes;
    m_qualification = qualification;
    m_itemNum = itemNum;
    m_brand = brand;
    m_purchasePrice = purchasePrice;
    m_retailPrice = retailPrice;
    m_memberPrice = memberPrice;
    m_creditScheme = creditScheme;
    m_conversion = conversion;
    m_discountScheme = discountScheme;
    m_warningNum = warningNum;
    m_productDate = productDate;
    m_lifeDate = lifeDate;
    m_warningDate = warningDate;
    m_batchNum = batchNum;
    m_remarks = remarks;
}

QString ProductType::productId() const
{
    return m_productId;
}

void ProductType::setProductId(const QString &productId)
{
    m_productId = productId;
}
QString ProductType::productName() const
{
    return m_productName;
}

void ProductType::setProductName(const QString &productName)
{
    m_productName = productName;
}
QString ProductType::unit() const
{
    return m_unit;
}

void ProductType::setUnit(const QString &unit)
{
    m_unit = unit;
}
QString ProductType::qualification() const
{
    return m_qualification;
}

void ProductType::setQualification(const QString &qualification)
{
    m_qualification = qualification;
}
QString ProductType::itemNum() const
{
    return m_itemNum;
}

void ProductType::setItemNum(const QString &itemNum)
{
    m_itemNum = itemNum;
}
QString ProductType::brand() const
{
    return m_brand;
}

void ProductType::setBrand(const QString &brand)
{
    m_brand = brand;
}
QString ProductType::purchasePrice() const
{
    return m_purchasePrice;
}

void ProductType::setPurchasePrice(const QString &purchasePrice)
{
    m_purchasePrice = purchasePrice;
}
QString ProductType::retailPrice() const
{
    return m_retailPrice;
}

void ProductType::setRetailPrice(const QString &retailPrice)
{
    m_retailPrice = retailPrice;
}
QString ProductType::memberPrice() const
{
    return m_memberPrice;
}

void ProductType::setMemberPrice(const QString &memberPrice)
{
    m_memberPrice = memberPrice;
}
QString ProductType::creditScheme() const
{
    return m_creditScheme;
}

void ProductType::setCreditScheme(const QString &creditScheme)
{
    m_creditScheme = creditScheme;
}
QString ProductType::conversion() const
{
    return m_conversion;
}

void ProductType::setConversion(const QString &conversion)
{
    m_conversion = conversion;
}
QString ProductType::discountScheme() const
{
    return m_discountScheme;
}

void ProductType::setDiscountScheme(const QString &discountScheme)
{
    m_discountScheme = discountScheme;
}
QString ProductType::warningNum() const
{
    return m_warningNum;
}

void ProductType::setWarningNum(const QString &warningNum)
{
    m_warningNum = warningNum;
}
QString ProductType::productDate() const
{
    return m_productDate;
}

void ProductType::setProductDate(const QString &productDate)
{
    m_productDate = productDate;
}
QString ProductType::lifeDate() const
{
    return m_lifeDate;
}

void ProductType::setLifeDate(const QString &lifeDate)
{
    m_lifeDate = lifeDate;
}
QString ProductType::warningDate() const
{
    return m_warningDate;
}

void ProductType::setWarningDate(const QString &warningDate)
{
    m_warningDate = warningDate;
}
QString ProductType::batchNum() const
{
    return m_batchNum;
}

void ProductType::setBatchNum(const QString &batchNum)
{
    m_batchNum = batchNum;
}
QString ProductType::remarks() const
{
    return m_remarks;
}

void ProductType::setRemarks(const QString &remarks)
{
    m_remarks = remarks;
}
QString ProductType::classes() const
{
    return m_classes;
}

void ProductType::setClasses(const QString &classes)
{
    m_classes = classes;
}



















