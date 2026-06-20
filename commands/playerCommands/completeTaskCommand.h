#pragma once
#include "iCommand.h"
#include "player.h"
class CompleteTaskCommand:public ICommand{
    Player& player;
    TaskBoard& taskBoard;
    int id;
    public:
    CompleteTaskCommand(Player& player, TaskBoard& taskBoard, int id);
    void execute()override;
};