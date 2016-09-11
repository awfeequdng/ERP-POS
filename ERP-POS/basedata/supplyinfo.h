#ifndef SUPPLYINFO_H
#define SUPPLYINFO_H

#include <QString>

class SupplyInfo
{
public:
    explicit SupplyInfo();

    SupplyInfo(const QString &supplyId,const QString &supplyName);

    SupplyInfo(const SupplyInfo &other);

    SupplyInfo operator = (const SupplyInfo &other);

    bool operator == (const SupplyInfo &other);
    bool operator < (const SupplyInfo &other);

    QString supplyName() const;
    void setSupplyName(const QString &supplyName);

    QString supplyId() const;
    void setSupplyId(const QString &supplyId);

private:
    QString m_supplyId;
    QString m_supplyName;

};

#endif // SUPPLYINFO_H
