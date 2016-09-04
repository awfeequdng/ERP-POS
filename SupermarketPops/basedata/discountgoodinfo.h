#ifndef DISCOUNTGOODINFO_H
#define DISCOUNTGOODINFO_H
#include <QString>

class DiscountGoodInfo
{
public:
    DiscountGoodInfo();
    QString getProductId() const;
    void setProductId(const QString &value);

    QString getProductName() const;
    void setProductName(const QString &value);

    QString getCredits() const;
    void setCredits(const QString &value);

    bool operator == (const DiscountGoodInfo &other);

private:
    QString productId;
    QString productName;
    QString credits;
};

typedef QList<DiscountGoodInfo> discountGoodInfoList;
#endif // DISCOUNTGOODINFO_H
