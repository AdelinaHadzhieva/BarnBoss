#pragma once
#include "user.h"
#include "barn.h"
#include "farm.h"
#include <string>

class Player : public User{
    Barn barn;
    Farm farm;
    int balance;
    int score;
    int currentCycles;
public:
    Player(const std::string& name, const std::string& password);
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
    void openMarketCatalog();
    void buyItem(int productId, int quantity);
    void sellItem(int productId, int quantity);
    void showTaskBoard()const;
    void completeTask(int taskId);
    auto operator<=>(const Player& other)const;
};