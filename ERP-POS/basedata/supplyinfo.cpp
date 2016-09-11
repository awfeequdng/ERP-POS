#include "supplyinfo.h"

SupplyInfo::SupplyInfo()
{
}

SupplyInfo::SupplyInfo(const QString &supplyId, const QString &supplyName)
{
    m_supplyId = supplyId;
    m_supplyName = supplyName;
}

SupplyInfo::SupplyInfo(const SupplyInfo &other)
{
    this->m_supplyName = other.m_supplyName;
    this->m_supplyId = other.m_supplyId;
}

SupplyInfo SupplyInfo::operator =(const SupplyInfo &other)
{
    if ( this == &other )
        return *this;

    this->m_supplyName = other.m_supplyName;
    this->m_supplyId = other.m_supplyId;

    return *this;
}

bool SupplyInfo::operator ==(const SupplyInfo &other)
{
    if ( this->m_supplyId == other.m_supplyId )
        return true;

    return false;
}

bool SupplyInfo::operator <(const SupplyInfo &other)
{
    if ( this->m_supplyId == other.m_supplyId )
        return true;

    return false;
}
QString SupplyInfo::supplyName() const
{
    return m_supplyName;
}

void SupplyInfo::setSupplyName(const QString &supplyName)
{
    m_supplyName = supplyName;
}
QString SupplyInfo::supplyId() const
{
    return m_supplyId;
}

void SupplyInfo::setSupplyId(const QString &supplyId)
{
    m_supplyId = supplyId;
}






