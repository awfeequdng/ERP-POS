#ifndef LOGINUSER_H
#define LOGINUSER_H

#include <Qstring>
#include <QList>


class LoginUser
{
public:
    LoginUser();
    LoginUser(const QString &user_Id,const QString &user_pwd);
    ~LoginUser();

    const QString getuser_Id() const;
    const QString getuser_pwd() const;

    void setuser_Id(const QString &);
    void setuser_pwd(const QString &);
private:
    QString user_Id;
    QString user_pwd;
};

typedef QList<LoginUser> LoginUserList;

#endif // LOGINUSER_H
