#include "userType.h"
std::string typeToString(const UserType& user){
    switch(user){
        case UserType::Guest: return "Guest";
        case UserType::Player: return "Player";
        case UserType::TaskManager: return "TaskManager";
        case UserType::MarketManager: return "MarketManager";
    }
}