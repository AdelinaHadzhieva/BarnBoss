#include "expandCommands.h"

    ExpandCroplandCommand::ExpandCroplandCommand(Player& player):player(player){}
    void ExpandCroplandCommand::execute(){
        player.expandCropland();
    }
    ExpandFarmlandCommand::ExpandFarmlandCommand(Player& player):player(player){}
    void ExpandFarmlandCommand::execute(){
        player.expandFarmland();
    }
