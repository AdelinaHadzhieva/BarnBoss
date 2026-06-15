#include "scoreboard.h"
void ScoreBoard::sortPlayers(const std::vector<std::unique_ptr<Player>>& players){
    std::sort(players.begin(),players.end(),
    [](const std::unique_ptr<Player> first,const std::unique_ptr<Player> second){
        if(first->checkScore()!=second->checkScore()) 
            return first->checkScore()>second->checkScore();
        if(first->checkBalance()!=second->checkBalance()) 
            return first->checkBalance()>second->checkBalance();
        return first->getId()< second->getId(););
    }
void ScoreBoard::scoreBoardInfo(const std::vector<std::unique_ptr<Player>>& players){
    sortPlayers(players);
    for(const auto& player:players){
        player->profileInfo();
    }
}