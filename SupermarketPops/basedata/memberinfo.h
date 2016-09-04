#ifndef MEMBERINFO_H
#define MEMBERINFO_H
#include <QString>

class memberInfo
{
public:
    memberInfo();
    memberInfo(const QString memberId,const QString memberType,const QString memberName,const QString beginCredit,
               const QString userCredit,const QString birthday,const QString birthWarn,const QString phoneNum,const QString email);

    QString memberId() const;
    void setMemberId(const QString &memberId);

    QString memberType() const;
    void setMemberType(const QString &memberType);

    QString memberName() const;
    void setMemberName(const QString &memberName);

    QString beginCredit() const;
    void setBeginCredit(const QString &beginCredit);

    QString userCredit() const;
    void setUserCredit(const QString &userCredit);

    QString birthday() const;
    void setBirthday(const QString &birthday);

    QString birthWarn() const;
    void setBirthWarn(const QString &birthWarn);

    QString phoneNum() const;
    void setPhoneNum(const QString &phoneNum);

    QString email() const;
    void setEmail(const QString &email);

private:
    QString m_memberId;
    QString m_memberType;
    QString m_memberName;
    QString m_beginCredit;
    QString m_userCredit;
    QString m_birthday;
    QString m_birthWarn;
    QString m_phoneNum;
    QString m_email;
};
typedef QList<memberInfo> memberInfoList;
#endif // MEMBERINFO_H
