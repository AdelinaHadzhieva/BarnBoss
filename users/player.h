#pragma once
#include <compare>
#include "user.h"
#include "../storage/barn.h"
#include "../storage/farm.h"
#include "../storage/market.h"
#include "../boards/taskBoard.h"

class Player : public User{
    Barn barn;
    Farm farm;
    int balance;
    int score;
    int currentCycles;
    void advanceTurn();
public:
    Player(const std::string& name, const std::string& password);
    int getId()const;
    void profileInfo()const override;
    int checkBalance()const;
    int checkScore()const;
    void checkBarn()const;
    void checkFarm()const;
    
    void expandCropland();
    void expandFarmland();
    void sowPlant(int seedId);
    void addAnimal(int animalId);
    void harvest();
    void openMarketCatalog(const Market& market)const;
    void buyItem(Market& market, int productId, int quantity);
    void sellItem(Market& market, int productId, int quantity);
    void showTaskBoard(const TaskBoard& taskBoard)const;
    void completeTask(TaskBoard& taskBoard, int taskId);
    std::strong_ordering operator<=> (const Player& other)const;
};