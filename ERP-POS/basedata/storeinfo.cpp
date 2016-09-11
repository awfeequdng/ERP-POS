#include "storeinfo.h"

storeInfo::storeInfo()
{
}

storeInfo::storeInfo(const QString &Number)
{
    m_Number = Number;
}

storeInfo::storeInfo(const storeInfo &other)
{
    this->m_Number = other.m_Number;
}

storeInfo storeInfo::operator =(const storeInfo &other)
{
    if ( this == &other )
        return *this;

    this->m_Number = other.m_Number;

    return *this;
}

//bool storeInfo::operator ==(const storeInfo &other)
//{
//    if ( this->m_productId == other.m_productId )
//        return true;

//    return false;
//}

//bool storeInfo::operator <(const storeInfo &other)
//{
//    if ( this->m_productId < other.m_productId )
//        return true;

//    return false;
//}

QString storeInfo::Number() const
{
    return m_Number;
}

void storeInfo::setNumber(const QString &Number)
{
    m_Number = Number;
}

