#ifndef STOREINFO_H
#define STOREINFO_H

#include <QObject>

class storeInfo : public QObject
{
    Q_OBJECT
public:
    explicit storeInfo(QObject *parent = 0);
    storeInfo(const QString &Number);

    storeInfo(const storeInfo &other);

    storeInfo operator =(const storeInfo &other);

//    bool operator ==(const storeInfo &other);
//    bool operator <(const storeInfo &other);

    QString Number() const;

    void setNumber(const QString &Number);

signals:

public slots:

private:
    QString m_Number;
};

#endif // STOREINFO_H
