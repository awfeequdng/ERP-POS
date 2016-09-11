#ifndef STOREINFO_H
#define STOREINFO_H

#include <QString>

class storeInfo
{
public:
    explicit storeInfo();
    storeInfo(const QString &Number);

    storeInfo(const storeInfo &other);

    storeInfo operator =(const storeInfo &other);

    QString Number() const;

    void setNumber(const QString &Number);

private:
    QString m_Number;
};

#endif // STOREINFO_H
