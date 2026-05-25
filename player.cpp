#include "player.h"


    Player::Player(const std::string& name, const std::string& password)
    :User(name,password),balance(100),score(0){}

    void Player::profileInfo()const override{
        std::print("ID: {}\n
        Username: {}\n Type: Player\n
        Balance: {}\n
        Score: {}\n
        ",id, username, balance, score);
    }

    int Player::checkBalance()const{
        return balance;
    }
    int Player::checkScore()const{
        return score;
    }
    void Player::checkBarn()const{
        barn.info();
    }
    void Player::checkFarm()const{
        std::print("Cropland capacity:{}, empty slots: {}", );
        std::print("Farmland capacity:{}, empty slots: {}", );
    }
    void Player::expandCropland(){

    }
    void Player::expandFarmland(){

    }
    void Player::sowPlant(int seedId){

    }
    void Player::addAnimal(int animalId){

    }
    void Player::harvest(){

    }
    void Player::openMarketCatalog(){

    }
    void Player::buyItem(int productId, int quantity){

    }
    void Player::sellItem(int productId, int quantity){

    }
    void Player::showTaskBoard()const{

    }
    void Player::completeTask(int taskId){

    }