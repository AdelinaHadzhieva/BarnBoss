#include "player.h"


    Player::Player(const std::string& name, const std::string& password)
    :User(name,password),balance(100),score(0){}

    void Player::profileInfo()const{
        std::print("ID: {}\nUsername: {}\n Type: Player\nBalance: {}\nScore: {}\n",
            id, username, balance, score);
    }
    int Player::getId()const{ return id; }

    int Player::checkBalance()const{ return balance;}

    int Player::checkScore()const{ return score;}

    void Player::checkBarn()const{ barn.info();}
    void Player::checkFarm()const{
        farm.info();
        
    }
    void Player::expandCropland(){

    }
    void Player::expandFarmland(){

    }
    void Player::sowPlant(int seedId){
        try{
            farm.addSeed(seedId);
            barn.remove(seedId);
            currentCycles++;
        }
        catch(const std::overflow_error& e){
            std::print("{}", e.what());
        }
        catch(const std::underflow_error& u){
            std::print("{}", u.what());
        }
        catch(const std::out_of_range& o){
            std::print("{}", o.what());
        }
    }
    void Player::addAnimal(int animalId){
        try{
            farm.addAnimal(animalId);
            barn.remove(animalId);
            currentCycles++;
        }
        catch(const std::overflow_error& e){
            std::print("{}",e.what());
        }
         catch(const std::underflow_error& u){
            std::print("{}", u.what());
        }
        catch(const std::out_of_range& o){
            std::print("{}", o.what());
        }
    }
    void Player::harvest(){

    }
    void Player::openMarketCatalog(const Market& market){
        market.info();
    }
    void Player::buyItem(Market& market, int productId, int quantity){
        
    }
    void Player::sellItem(int productId, int quantity){

    }
    void Player::showTaskBoard(const TaskBoard& taskBoard)const{
        taskBoard.showinfo();
    }
    void Player::completeTask(TaskBoard& taskBoard, int taskId){

    }
    auto Player::operator<=>(const Player& other)const{
        if(auto cmp = score <=> other.score; cmp!=0){
            return cmp;
        }
        if(auto cmp = balance <=> other.balance; cmp!=0){
            return cmp;
        }
        return !(id<=>other.id);

    }