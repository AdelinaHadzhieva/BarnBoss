#pragma once
#include <fstream>
#include <iostream>
#include "./users/player.h"
#include "./users/taskManager.h"
#include "./users/marketManager.h"
#include "./boards/scoreboard.h"
#include "./commands/commandFactory.h"
#include "userType.h"


class GameSystem{
    TaskBoard taskBoard;
    Market market;
    ScoreBoard scoreBoard;
    std::vector<std::unique_ptr<Player>> players;
    std::unique_ptr<TaskManager> taskManager;
    std::unique_ptr<MarketManager> marketManager;
    size_t activePlayer = 0;

    UserType currentUser = UserType::Guest;

    GameSystem() ;
    GameSystem(const GameSystem& ) = delete;
    GameSystem& operator=(const GameSystem&) = delete;

    public:
    const User* getCurrentUser() ;
    Player& getActivePlayer();
    Market& getMarket();
    TaskBoard& getTaskBoard();
    const UserType& getCurrentUserType() const;
    MarketManager& getMarketManager();
    TaskManager& getTaskManager();


    static GameSystem& getInstance();

    void Register(const std::string& username, const std::string& password, const std::string& type);
    void login(const std::string& username,const std::string& password);
    void loadFromFile();
    void exit();
    void run();
};