#include "harvestCommand.h"
HarvestCommand::HarvestCommand(Player& player):player(player){}
    void HarvestCommand::execute(){
        player.harvest();
    }