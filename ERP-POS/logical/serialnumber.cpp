#include "serialnumber.h"
#include <QString>
#include <QDateTime>
#include <QDebug>

SerialNumber::SerialNumber()
{
}

QString SerialNumber::getSerialNumberStr()
{
    QString str;
    static QString lastDateTimeStr = "19700101";;//初始设为1970年1月1日0点0时0分0秒
    static int flownumber = 0;//范围1-9999循环往复

    QDateTime dt = QDateTime::currentDateTime();
    QString currDateTimeStr = dt.toString("yyyyMMdd");
    if(currDateTimeStr > lastDateTimeStr)
    {
        lastDateTimeStr = currDateTimeStr;//刷新最新的时间字符串
        flownumber = 0;//清零

    }
    if(flownumber < 9999)
    {
        flownumber++;
      //  qDebug()<<"flownumber"<<flownumber;

    }else
    {
        flownumber = 0;
    }
    QString num = QString::number(flownumber);
    //pv(QString::number(flownumber));
    str = currDateTimeStr + num;
    //pv(str);
    return str;
}
