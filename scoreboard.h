#pragma once
#include <print>
#include <vector>
#include <memory>
#include "player.h"
class ScoreBoard{
    public:
    ScoreBoard() = default;
    std::vector<const Player*> sortPlayers(const std::vector<std::unique_ptr<Player>>& players);
    void scoreBoardInfo(const std::vector<std::unique_ptr<Player>>& players);
};