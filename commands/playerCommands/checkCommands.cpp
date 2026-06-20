#include "checkCommands.h"
CheckBalanceCommand::CheckBalanceCommand(Player& player):player(player){}
void CheckBalanceCommand::execute(){
    std::print("Balance: {}", player.checkBalance());
}

CheckScoreCommand::CheckScoreCommand(Player& player):player(player){}
void CheckScoreCommand::execute(){
    std::print("Score: {}", player.checkScore());
}

CheckBarnCommand::CheckBarnCommand(Player& player):player(player){}
void CheckBarnCommand::execute(){
    player.checkBarn();
}

CheckFarmCommand::CheckFarmCommand(Player& player):player(player){}
void CheckFarmCommand::execute(){
    player.checkFarm();
}