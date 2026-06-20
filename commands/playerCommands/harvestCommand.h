#pragma once
#include "iCommand.h"
#include "player.h"
class HarvestCommand:public ICommand{
    Player& player;
    public:
    HarvestCommand(Player& player);
    void execute()override;
};