#pragma once
#include "user.h"
#include "barn.h"
#include "farm.h"
#include "market.h"
#include "taskBoard.h"
#include <string>

class Player : public User{
    Barn barn;
    Farm farm;
    int balance;
    int score;
    int currentCycles;
public:
    Player(const std::string& name, const std::string& password);
    void getScore()const;
    void getBalance()const;
    void getId()const;
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
    void openMarketCatalog(const Market& market);
    void buyItem(Market& market, int productId, int quantity);
    void sellItem(Market& market, int productId, int quantity);
    void showTaskBoard(const TaskBoard& taskBoard)const;
    void completeTask(TaskBoard& taskBoard, int taskId);
    auto operator<=>(const Player& other)const;
};