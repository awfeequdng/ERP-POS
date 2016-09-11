#include "staffinfo.h"

staffInfo::staffInfo()
{  
}

staffInfo::staffInfo(const QString &staffId, const QString &staffName)
{
    m_staffId = staffId;
    m_staffName = staffName;
}

staffInfo::staffInfo(const staffInfo &other)
{
    this->m_staffId = other.m_staffId;
    this->m_staffName = other.m_staffName;
}

staffInfo staffInfo::operator =(const staffInfo &other)
{
    if ( this == &other )
        return *this;

    this->m_staffId = other.m_staffId;
    this->m_staffName = other.m_staffName;

    return *this;
}
QString staffInfo::staffId() const
{
    return m_staffId;
}

void staffInfo::setStaffId(const QString &staffId)
{
    m_staffId = staffId;
}
QString staffInfo::staffName() const
{
    return m_staffName;
}

void staffInfo::setStaffName(const QString &staffName)
{
    m_staffName = staffName;
}


