#include "loginuser.h"

LoginUser::LoginUser()
{

}

LoginUser::LoginUser(const QString &user_Id,const QString &user_pwd)
{
    this->user_Id = user_Id;
    this->user_pwd = user_pwd;
}

LoginUser::~LoginUser()
{

}

const QString LoginUser::getuser_Id() const
{
    return user_Id;
}
const QString LoginUser::getuser_pwd() const
{
    return user_pwd;
}
void LoginUser::setuser_Id(const QString &user_Id)
{
    this->user_Id = user_Id;
}
void LoginUser::setuser_pwd(const QString &user_pwd)
{
    this->user_pwd = user_pwd;
}
