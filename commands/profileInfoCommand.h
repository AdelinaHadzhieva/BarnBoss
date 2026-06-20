#pragma once 
#include "iCommand.h"
#include "user.h"
#include "player.h"
#include "taskManager.h"
#include "marketManager.h"
class ProfileInfoCommand:public ICommand{
    const User* user;
    public:
    ProfileInfoCommand(const User* user);
    void execute()override;
};