#include "user.h"
#include <print>
User::User(const std::string& username,const std::string& password)
:username(username),password(password){
    isLoggedIn=true;
}
void User::logout(){
    isLoggedIn=false;
}
void User::changePassword(const std::string& newPassword){
    password=newPassword;
}
void profileInfo(){
    std::print("ID:{}\nUsername:{}\n", id, username);
}
