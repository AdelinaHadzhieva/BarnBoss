#include "user.h"
#include <print>
int User::idCounter=0;
User::User(const std::string& username,const std::string& password)
:username(username), id(++idCounter){
    if(password.size() < 3){
        throw std::invalid_argument("Password must be at least 3 characters!");
    }
    isLoggedIn = true;
}
void User::logout(){
    isLoggedIn = false;
}
void User::changePassword(const std::string& newPassword){
    password = newPassword;
}
const std::string& MarketManager::getName()const{
    return username;
}
const std::string& MarketManager::getPass()const{
    return password;
}

