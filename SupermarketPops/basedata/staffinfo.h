#ifndef STAFFINFO_H
#define STAFFINFO_H

#include <QObject>

class staffInfo : public QObject
{
    Q_OBJECT
public:
    explicit staffInfo(QObject *parent = 0);

    staffInfo(const QString &staffId,const QString &staffName);

    staffInfo(const staffInfo &other);

    staffInfo operator =(const staffInfo &other);

    bool operator == (const staffInfo &other);
    bool operator < (const staffInfo &other);

    QString staffId() const;
    void setStaffId(const QString &staffId);

    QString staffName() const;
    void setStaffName(const QString &staffName);

signals:

public slots:

private:
    QString m_staffId;
    QString m_staffName;

};

#endif // STAFFINFO_H
