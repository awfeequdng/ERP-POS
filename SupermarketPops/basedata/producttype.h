#ifndef PRODUCTTYPE_H
#define PRODUCTTYPE_H

#include <QObject>

class ProductType : public QObject
{
    Q_OBJECT
public:
    explicit ProductType(QObject *parent = 0);

    ProductType(const ProductType &other);

    ProductType operator =(const ProductType &other);

    bool operator ==(const ProductType &other);
    bool operator <(const ProductType &other);

    ProductType(const QString &id, const QString &name, const QString &unit, const QString &classes, const QString &qualification,
                const QString &itemNum, const QString &brand, const QString &purchasePrice,
                const QString &retailPrice, const QString &memberPrice, const QString &creditScheme,
                const QString &conversion, const QString &discountScheme, const QString &warningNum,
                const QString &productDate, const QString &lifeDate, const QString &warningDate,
                const QString &batchNum, const QString &remarks, QObject *parent = 0);

    QString productId() const;
    void setProductId(const QString &productId);

    QString productName() const;
    void setProductName(const QString &productName);

    QString unit() const;
    void setUnit(const QString &unit);

    QString qualification() const;
    void setQualification(const QString &qualification);

    QString itemNum() const;
    void setItemNum(const QString &itemNum);

    QString brand() const;
    void setBrand(const QString &brand);

    QString purchasePrice() const;
    void setPurchasePrice(const QString &purchasePrice);

    QString retailPrice() const;
    void setRetailPrice(const QString &retailPrice);

    QString memberPrice() const;
    void setMemberPrice(const QString &memberPrice);

    QString creditScheme() const;
    void setCreditScheme(const QString &creditScheme);

    QString conversion() const;
    void setConversion(const QString &conversion);

    QString discountScheme() const;
    void setDiscountScheme(const QString &discountScheme);

    QString warningNum() const;
    void setWarningNum(const QString &warningNum);

    QString productDate() const;
    void setProductDate(const QString &productDate);

    QString lifeDate() const;
    void setLifeDate(const QString &lifeDate);

    QString warningDate() const;
    void setWarningDate(const QString &warningDate);

    QString batchNum() const;
    void setBatchNum(const QString &batchNum);

    QString remarks() const;
    void setRemarks(const QString &remarks);

    QString classes() const;
    void setClasses(const QString &classes);

signals:

public slots:

private:
    QString m_productId;
    QString m_productName;
    QString m_unit;
    QString m_classes;
    QString m_qualification;
    QString m_itemNum;
    QString m_brand;
    QString m_purchasePrice;
    QString m_retailPrice;
    QString m_memberPrice;
    QString m_creditScheme;
    QString m_conversion;
    QString m_discountScheme;
    QString m_warningNum;
    QString m_productDate;
    QString m_lifeDate;
    QString m_warningDate;
    QString m_batchNum;
    QString m_remarks;
};

#endif // PRODUCTTYPE_H
