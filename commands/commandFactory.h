#pragma once
#include "iCommand.h"
#include <string>
#include <vector>
#include <memory>
class GameSystem;

class CommandFactory{
    public:
    
    static std::unique_ptr<ICommand> create(const std::vector<std::string>& tokens, GameSystem& sys);
};