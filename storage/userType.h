#pragma once
#include <string>
enum class UserType{Guest, Player, TaskManager, MarketManager};
std::string typeToString(const UserType& user);