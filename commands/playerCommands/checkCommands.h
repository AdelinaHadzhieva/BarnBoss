#pragma once
#include "iCommand.h"
#include "player.h"
class CheckBalanceCommand:public ICommand{
    Player& player;
    public:
    CheckBalanceCommand(Player& player);
    void execute()override;
};
class CheckScoreCommand:public ICommand{
    Player& player;
    public:
    CheckScoreCommand(Player& player);
    void execute()override;
};
class CheckBarnCommand:public ICommand{
    Player& player;
    public:
    CheckBarnCommand(Player& player);
    void execute()override;
};
class CheckFarmCommand:public ICommand{
    Player& player;
    public:
    CheckFarmCommand(Player& player);
    void execute()override;
};