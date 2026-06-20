#pragma once
#include <string>
#include <memory>

class ICommand {
public:
    virtual void execute() = 0;
    virtual ~ICommand() = default;
};