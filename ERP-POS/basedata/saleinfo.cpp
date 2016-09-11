#include "saleinfo.h"

saleInfo::saleInfo()
{
}

saleInfo::saleInfo(const QString &saleDate, const QString &serialNumber,
                   const QString &saleNum, const QString &profit,
                   const QString &profitRate,const QString &saleSum, const QString &salenumSum,
                   const QString &purchaseSum, const QString &discountSum,
                   const QString &favorableSum, const QString &profitSum,
                   const QString &shouldreceive, const QString &reallyreceive, const QString &change)
{
    m_saleDate = saleDate;
    m_serialNumber = serialNumber;
    m_saleNum = saleNum;
    m_profit = profit;
    m_profitRate = profitRate;

    m_salenumSum = salenumSum;
    m_saleSum = saleSum;
    m_purchaseSum = purchaseSum;
    m_discountSum = discountSum;
    m_favorableSum = favorableSum;
    m_profitSum = profitSum;

    m_shouldreceive = shouldreceive;
    m_reallyreceive = reallyreceive;
    m_change = change;


}
saleInfo::saleInfo(const saleInfo &other)
{
    this->m_saleDate = other.m_saleDate;
    this->m_serialNumber = other.m_serialNumber;
    this->m_saleNum = other.m_saleNum;
    this->m_profit = other.m_profit;
    this->m_profitRate = other.m_profitRate;

    this->m_salenumSum = other.m_salenumSum;
    this->m_saleSum = other.m_saleSum;
    this->m_purchaseSum = other.m_purchaseSum;
    this->m_discountSum = other.m_discountSum;
    this->m_favorableSum = other.m_favorableSum;
    this->m_profitSum = other.m_profitSum;

    this->m_shouldreceive = other.m_shouldreceive;
    this->m_reallyreceive = other.m_reallyreceive;
    this->m_change = other.m_change;
}

saleInfo saleInfo::operator =(const saleInfo &other)
{
    if ( this == &other )
        return *this;

    this->m_saleDate = other.m_saleDate;
    this->m_serialNumber = other.m_serialNumber;
    this->m_saleNum = other.m_saleNum;
    this->m_profit = other.m_profit;
    this->m_profitRate = other.m_profitRate;

    this->m_salenumSum = other.m_salenumSum;
    this->m_saleSum = other.m_saleSum;
    this->m_purchaseSum = other.m_purchaseSum;
    this->m_discountSum = other.m_discountSum;
    this->m_favorableSum = other.m_favorableSum;
    this->m_profitSum = other.m_profitSum;

    this->m_shouldreceive = other.m_shouldreceive;
    this->m_reallyreceive = other.m_reallyreceive;
    this->m_change = other.m_change;

    return *this;
}

//bool saleInfo::operator ==(const saleInfo &other)
//{
//    if ( this->m_productId == other.m_productId )
//        return true;

//    return false;
//}

//bool saleInfo::operator <(const saleInfo &other)
//{
//    if ( this->m_productId < other.m_productId )
//        return true;

//    return false;
//}

QString saleInfo::saleDate() const
{
    return m_saleDate;
}

void saleInfo::setSaleDate(const QString &saleDate)
{
    m_saleDate = saleDate;
}
QString saleInfo::serialNumber() const
{
    return m_serialNumber;
}

void saleInfo::setSerialNumber(const QString &serialNumber)
{
    m_serialNumber = serialNumber;
}
QString saleInfo::saleNum() const
{
    return m_saleNum;
}

void saleInfo::setSaleNum(const QString &saleNum)
{
    m_saleNum = saleNum;
}
QString saleInfo::profit() const
{
    return m_profit;
}

void saleInfo::setProfit(const QString &profit)
{
    m_profit = profit;
}
QString saleInfo::profitRate() const
{
    return m_profitRate;
}

void saleInfo::setProfitRate(const QString &profitRate)
{
    m_profitRate = profitRate;
}
QString saleInfo::salenumSum() const
{
    return m_salenumSum;
}

void saleInfo::setSalenumSum(const QString &salenumSum)
{
    m_salenumSum = salenumSum;
}
QString saleInfo::saleSum() const
{
    return m_saleSum;
}

void saleInfo::setSaleSum(const QString &saleSum)
{
    m_saleSum = saleSum;
}
QString saleInfo::purchaseSum() const
{
    return m_purchaseSum;
}

void saleInfo::setPurchaseSum(const QString &purchaseSum)
{
    m_purchaseSum = purchaseSum;
}
QString saleInfo::discountSum() const
{
    return m_discountSum;
}

void saleInfo::setDiscountSum(const QString &discountSum)
{
    m_discountSum = discountSum;
}
QString saleInfo::favorableSum() const
{
    return m_favorableSum;
}

void saleInfo::setFavorableSum(const QString &favorableSum)
{
    m_favorableSum = favorableSum;
}
QString saleInfo::profitSum() const
{
    return m_profitSum;
}

void saleInfo::setProfitSum(const QString &profitSum)
{
    m_profitSum = profitSum;
}
QString saleInfo::shouldreceive() const
{
    return m_shouldreceive;
}

void saleInfo::setShouldreceive(const QString &shouldreceive)
{
    m_shouldreceive = shouldreceive;
}
QString saleInfo::reallyreceive() const
{
    return m_reallyreceive;
}

void saleInfo::setReallyreceive(const QString &reallyreceive)
{
    m_reallyreceive = reallyreceive;
}
QString saleInfo::change() const
{
    return m_change;
}

void saleInfo::setChange(const QString &change)
{
    m_change = change;
}



