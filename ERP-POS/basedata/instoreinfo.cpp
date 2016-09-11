#include "instoreinfo.h"

InstoreInfo::InstoreInfo()
{
}

InstoreInfo::InstoreInfo(const QString &instoreDate, const QString &instoreNum)
{
    m_instoreDate = instoreDate;
    m_instoreNum = instoreNum;

}

InstoreInfo::InstoreInfo(const InstoreInfo &other )
{
   this->m_instoreNum = other.m_instoreNum;
    this->m_instoreDate = other.m_instoreDate;
}

InstoreInfo InstoreInfo::operator =(const InstoreInfo &other )
{
    if ( this == &other )
        return *this;

    this->m_instoreNum = other.m_instoreNum;
    this->m_instoreDate = other.m_instoreDate;

    return *this;
}

//bool InstoreInfo::operator ==(const InstoreInfo &other)
//{
//    if ( this->m_productId == other.m_productId )
//        return true;

//    return false;
//}

//bool InstoreInfo::operator <(const InstoreInfo &other)
//{
//    if ( this->m_productId < other.m_productId )
//        return true;

//    return false;
//}

QString InstoreInfo::instoreDate() const
{
    return m_instoreDate;
}

void InstoreInfo::setInstoreDate(const QString &instoreDate)
{
    m_instoreDate = instoreDate;
}
QString InstoreInfo::instoreNum() const
{
    return m_instoreNum;
}

void InstoreInfo::setInstoreNum(const QString &instoreNum)
{
    m_instoreNum = instoreNum;
}
