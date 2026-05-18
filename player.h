#pragma once
class Player : public User{
    Barn barn;
    Farm farm;
    int balance=100;
    int score=0;
public:
    int checkBalance()const;
    int chackScore()const;
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
}