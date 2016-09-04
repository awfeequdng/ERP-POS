#ifndef INSTOREINFO_H
#define INSTOREINFO_H

#include <QObject>

class InstoreInfo : public QObject
{
    Q_OBJECT
public:
    explicit InstoreInfo(QObject *parent = 0);

    InstoreInfo(const QString &instoreDate, const QString &instoreNum);


    QString instoreDate() const;
    void setInstoreDate(const QString &instoreDate);

    QString instoreNum() const;
    void setInstoreNum(const QString &instoreNum);

    InstoreInfo( const InstoreInfo &other );

    InstoreInfo operator =( const InstoreInfo &other );

//    bool operator ==(const InstoreInfo &other);
//    bool operator <(const InstoreInfo &other);

signals:

public slots:

private:
    QString m_instoreDate;
    QString m_instoreNum;

};

#endif // INSTOREINFO_H
