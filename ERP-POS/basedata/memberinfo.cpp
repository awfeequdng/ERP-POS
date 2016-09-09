#include "memberinfo.h"

memberInfo::memberInfo()
{

}

memberInfo::memberInfo(const QString memberId, const QString memberType,
                       const QString memberName, const QString beginCredit, const QString userCredit,
                       const QString birthday, const QString birthWarn, const QString phoneNum, const QString email)
{
    m_memberId = memberId;
    m_memberType = memberType;
    m_memberName = memberName;
    m_beginCredit = beginCredit;
    m_userCredit = userCredit;
    m_birthday = birthday;
    m_birthWarn = birthWarn;
    m_phoneNum = phoneNum;
    m_email = email;
}

QString memberInfo::memberId() const
{
    return m_memberId;
}

void memberInfo::setMemberId(const QString &memberId)
{
    m_memberId = memberId;
}
QString memberInfo::memberType() const
{
    return m_memberType;
}

void memberInfo::setMemberType(const QString &memberType)
{
    m_memberType = memberType;
}
QString memberInfo::memberName() const
{
    return m_memberName;
}

void memberInfo::setMemberName(const QString &memberName)
{
    m_memberName = memberName;
}
QString memberInfo::beginCredit() const
{
    return m_beginCredit;
}

void memberInfo::setBeginCredit(const QString &beginCredit)
{
    m_beginCredit = beginCredit;
}
QString memberInfo::userCredit() const
{
    return m_userCredit;
}

void memberInfo::setUserCredit(const QString &userCredit)
{
    m_userCredit = userCredit;
}
QString memberInfo::birthday() const
{
    return m_birthday;
}

void memberInfo::setBirthday(const QString &birthday)
{
    m_birthday = birthday;
}
QString memberInfo::birthWarn() const
{
    return m_birthWarn;
}

void memberInfo::setBirthWarn(const QString &birthWarn)
{
    m_birthWarn = birthWarn;
}
QString memberInfo::phoneNum() const
{
    return m_phoneNum;
}

void memberInfo::setPhoneNum(const QString &phoneNum)
{
    m_phoneNum = phoneNum;
}
QString memberInfo::email() const
{
    return m_email;
}

void memberInfo::setEmail(const QString &email)
{
    m_email = email;
}










