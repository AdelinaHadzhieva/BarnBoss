#include "scoreboard.h"
std::vector<Player*> ScoreBoard::sortPlayers(const std::vector<std::unique_ptr<Player>>& players){
    std::vector<Player*> sortedPlayers;
    sortedPlayers.reserve(players.size()); 

    for (const auto& player : players) {
        if (player) {
            sortedPlayers.push_back(player.get());
        }
    }

    std::sort(sortedPlayers.begin(),sortedPlayers.end(),
    [](const Player* first, const Player* second){
        return *first > *second;
    });

    return sortedPlayers;
    }
void ScoreBoard::scoreBoardInfo(const std::vector<std::unique_ptr<Player>>& players){

    std::vector<Player*> sortedPlayers = sortPlayers(players);
    std::print("=== SCORE BOARD ===\n");
    int scoreBoardID = 1;
    for(const auto& player:sortedPlayers){
        std::print("{}. {:<8}      |Score: {}  Balance: {}\n", 
            player->getId(), player->getName(),player->checkScore(),player->checkBalance());
    }
}