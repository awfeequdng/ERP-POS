#ifndef OUTSTOREINFO_H
#define OUTSTOREINFO_H

#include <QObject>

class outStoreInfo
{
public:
    explicit outStoreInfo();
    outStoreInfo(const QString &outstoreDate,const QString &outstoreprice,const QString &outstoreNum);

    outStoreInfo(const QString &outstoreprice,const QString &outstoreNum);
    outStoreInfo(const outStoreInfo &other);

    outStoreInfo operator =(const outStoreInfo &other);

    QString outstoreDate() const;
    void setOutstoreDate(const QString &outstoreDate);

    QString outstoreprice() const;
    void setOutstoreprice(const QString &outstoreprice);

    QString outstoreNum() const;
    void setOutstoreNum(const QString &outstoreNum);

signals:

public slots:

private:
    QString m_outstoreDate;
    QString m_outstoreprice;
    QString m_outstoreNum;

};

#endif // OUTSTOREINFO_H
