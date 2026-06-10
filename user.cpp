#include "user.h"
#include <print>
int User::idCounter=0;
User::User(const std::string& username,const std::string& password)
:username(username), password(password), id(++idCounter){
    isLoggedIn = true;
}
void User::logout(){
    isLoggedIn = false;
}
void User::changePassword(const std::string& newPassword){
    password = newPassword;
}

