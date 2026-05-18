#pragma once
#include <string>
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
    void profileInfo();


};