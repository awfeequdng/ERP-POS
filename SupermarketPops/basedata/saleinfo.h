#ifndef SALEINFO_H
#define SALEINFO_H

#include <QObject>

class saleInfo : public QObject
{
    Q_OBJECT
public:
    explicit saleInfo(QObject *parent = 0);

    saleInfo(const QString &saleDate, const QString &serialNumber, const QString &saleNum,
             const QString &profit, const QString &profitRate, const QString &salenumSum,
             const QString &saleSum, const QString &purchaseSum, const QString &discountSum,
             const QString &favorableSum, const QString &profitSum,
             const QString &shouldreceive, const QString &reallyreceive, const QString &change);

    saleInfo(const saleInfo &other);

    saleInfo operator =(const saleInfo &other);

//    bool operator ==(const saleInfo &other);
//    bool operator <(const saleInfo &other);

    QString saleDate() const;
    void setSaleDate(const QString &saleDate);

    QString serialNumber() const;
    void setSerialNumber(const QString &serialNumber);

    QString saleNum() const;
    void setSaleNum(const QString &saleNum);

    QString profit() const;
    void setProfit(const QString &profit);

    QString profitRate() const;
    void setProfitRate(const QString &profitRate);



    QString salenumSum() const;
    void setSalenumSum(const QString &salenumSum);

    QString saleSum() const;
    void setSaleSum(const QString &saleSum);

    QString purchaseSum() const;
    void setPurchaseSum(const QString &purchaseSum);

    QString discountSum() const;
    void setDiscountSum(const QString &discountSum);

    QString favorableSum() const;
    void setFavorableSum(const QString &favorableSum);

    QString profitSum() const;
    void setProfitSum(const QString &profitSum);


    QString shouldreceive() const;
    void setShouldreceive(const QString &shouldreceive);

    QString reallyreceive() const;
    void setReallyreceive(const QString &reallyreceive);

    QString change() const;
    void setChange(const QString &change);

signals:

public slots:

private:
    QString m_saleDate;
    QString m_serialNumber;
    QString m_saleNum;
    QString m_profit;
    QString m_profitRate;
    QString m_salenumSum;
    QString m_saleSum;
    QString m_purchaseSum;
    QString m_discountSum;
    QString m_favorableSum;
    QString m_profitSum;

    QString m_shouldreceive;
    QString m_reallyreceive;
    QString m_change;

};

#endif // SALEINFO_H
