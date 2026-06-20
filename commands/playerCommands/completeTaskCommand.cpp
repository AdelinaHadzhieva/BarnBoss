#include "completeTaskCommand.h"
CompleteTaskCommand::CompleteTaskCommand(Player& player, TaskBoard& taskBoard, int id)
: player(player),taskBoard(taskBoard), id(id){}
    void CompleteTaskCommand::execute(){
        player.completeTask(taskBoard, id);
    }