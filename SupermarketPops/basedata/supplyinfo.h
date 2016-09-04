#ifndef SUPPLYINFO_H
#define SUPPLYINFO_H

#include <QObject>

class SupplyInfo : public QObject
{
    Q_OBJECT
public:
    explicit SupplyInfo(QObject *parent = 0);

    SupplyInfo(const QString &supplyId,const QString &supplyName);

    SupplyInfo(const SupplyInfo &other);

    SupplyInfo operator = (const SupplyInfo &other);

    bool operator == (const SupplyInfo &other);
    bool operator < (const SupplyInfo &other);

    QString supplyName() const;
    void setSupplyName(const QString &supplyName);

    QString supplyId() const;
    void setSupplyId(const QString &supplyId);

signals:

public slots:

private:
    QString m_supplyId;
    QString m_supplyName;

};

#endif // SUPPLYINFO_H
