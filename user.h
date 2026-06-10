#pragma once
#include <string>
#include <print>
#include <memory>
#include <exception>
class User{
    protected:
    static int idCounter;
    int id;
    bool isLoggedIn;
    std::string username;
    std::string password;
    
    public:
    User(const std::string& username,const std::string& password);
    void logout();
    void changePassword(const std::string& newPassword);
    virtual void profileInfo()const=0;
    //virtual std::unique_ptr<User> clone()=0;
    virtual ~User()=default;

};