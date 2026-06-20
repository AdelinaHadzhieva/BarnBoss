#include "addToFarmCommands.h"
SowPlantCommand::SowPlantCommand(Player& player, int id):player(player),id(id){}
    void SowPlantCommand::execute(){
        player.sowPlant(id);
    }
AddAnimalCommand::AddAnimalCommand(Player& player, int id):player(player),id(id){}
    void AddAnimalCommand::execute(){
        player.addAnimal(id);
    }