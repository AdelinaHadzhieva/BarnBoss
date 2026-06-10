#include "player.h"

    Player::Player(const std::string& name, const std::string& password)
    :User(name,password),balance(100),score(0){}

    void Player::profileInfo()const{
        std::print("ID: {}\nUsername: {}\n Type: Player\nBalance: {}\nScore: {}\n",
            id, username, balance, score);
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
    void Player::completeTask(int taskId){}