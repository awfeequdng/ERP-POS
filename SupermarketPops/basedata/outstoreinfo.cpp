#include "outstoreinfo.h"

outStoreInfo::outStoreInfo(QObject *parent) :
    QObject(parent)
{
}

outStoreInfo::outStoreInfo(const QString &outstoreDate, const QString &outstoreprice, const QString &outstoreNum)
{
    m_outstoreDate = outstoreDate;
    m_outstoreprice = outstoreprice;
    m_outstoreNum = outstoreNum;

}

outStoreInfo::outStoreInfo(const QString &outstoreprice, const QString &outstoreNum)
{
    m_outstoreprice = outstoreprice;
    m_outstoreNum = outstoreNum;
}

outStoreInfo::outStoreInfo(const outStoreInfo &other)
{
    this->m_outstoreDate = other.m_outstoreDate;
    this->m_outstoreNum = other.m_outstoreNum;
    this->m_outstoreprice = other.m_outstoreprice;
}

outStoreInfo outStoreInfo::operator =(const outStoreInfo &other)
{
    if ( this == &other )
        return *this;

    this->m_outstoreDate = other.m_outstoreDate;
    this->m_outstoreNum = other.m_outstoreNum;
    this->m_outstoreprice = other.m_outstoreprice;

    return *this;
}

//bool outStoreInfo::operator ==(const outStoreInfo &other)
//{
//    if ( this->m_productId == other.m_productId )
//        return true;

//    return false;
//}

//bool outStoreInfo::operator <(const outStoreInfo &other)
//{
//    if ( this->m_productId < other.m_productId )
//        return true;

//    return false;
//}

QString outStoreInfo::outstoreDate() const
{
    return m_outstoreDate;
}

void outStoreInfo::setOutstoreDate(const QString &outstoreDate)
{
    m_outstoreDate = outstoreDate;
}

QString outStoreInfo::outstoreprice() const
{
    return m_outstoreprice;
}

void outStoreInfo::setOutstoreprice(const QString &outstoreprice)
{
    m_outstoreprice = outstoreprice;
}
QString outStoreInfo::outstoreNum() const
{
    return m_outstoreNum;
}

void outStoreInfo::setOutstoreNum(const QString &outstoreNum)
{
    m_outstoreNum = outstoreNum;
}


