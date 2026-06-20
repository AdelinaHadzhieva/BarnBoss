#pragma once
#include "iCommand.h"
#include "player.h"
class SowPlantCommand:public ICommand{
    Player& player;
    int id;
    public:
    SowPlantCommand(Player& player, int id);
    void execute()override;
};

class AddAnimalCommand:public ICommand{
    Player& player;
    int id;
    public:
    AddAnimalCommand(Player& player, int id);
    void execute()override;
};