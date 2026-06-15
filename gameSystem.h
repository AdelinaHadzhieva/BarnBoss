#pragma once
#include <fstream>
#include "player.h"
#include "taskManager.h"
#include "marketManager.h"
#include "scoreboard.h"


class GameSystem{
    TaskBoard taskboard;
    Market market;
    ScoreBoard scoreboard;
    std::vector<std::unique_ptr<Player>> players;
    std::unique_ptr<TaskManager> taskManager;
    std::unique_ptr<MarketManager> marketManager;
    GameSystem();
    GameSystem(const GameSystem& )=delete;
    GameSystem& operator=(const GameSystem&)=delete;

    public:
    static GameSystem& getInstance();
    void Register(const std::string& username, const std::string& password, const std::string& type);
    void login(const std::string& username,const std::string& password);
    void exit();
};