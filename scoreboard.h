#pragma once
#include <print>
#include <vector>
#include <memory>
#include "player.h"
class ScoreBoard{
    public:
    void sortPlayers(const std::vector<std::unique_ptr<Player>>& players);
    void showScoreBoard();
};