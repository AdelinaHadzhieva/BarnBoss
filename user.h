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
    const std::string& getName()const;
    const std::string& getPass()const;
    void changePassword(const std::string& newPassword);
    virtual void profileInfo()const=0;
    
    virtual ~User()=default;

};