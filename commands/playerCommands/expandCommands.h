#pragma once 
#include "iCommand.h"
#include "player.h"
class ExpandCroplandCommand:public ICommand{
    Player& player;
    public:
    ExpandCroplandCommand(Player& player);
    void execute()override;
};

class ExpandFarmlandCommand:public ICommand{
    Player& player;
    public:
    ExpandFarmlandCommand(Player& player);
    void execute()override;
};