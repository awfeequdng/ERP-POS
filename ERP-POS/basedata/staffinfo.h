#ifndef STAFFINFO_H
#define STAFFINFO_H

#include <QString>

class staffInfo
{
public:
    explicit staffInfo();

    staffInfo(const QString &staffId,const QString &staffName);

    staffInfo(const staffInfo &other);

    staffInfo operator =(const staffInfo &other);

    bool operator == (const staffInfo &other);
    bool operator < (const staffInfo &other);

    QString staffId() const;
    void setStaffId(const QString &staffId);

    QString staffName() const;
    void setStaffName(const QString &staffName);

private:
    QString m_staffId;
    QString m_staffName;

};

#endif // STAFFINFO_H
