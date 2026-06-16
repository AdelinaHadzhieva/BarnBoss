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

    void Player::checkFarm()const{ farm.info();}

    void Player::expandCropland(){
        try{
        if(score >= farm.getCropCapacity()*10 && balance >= farm.getCropCapacity()*50){
            balance-=farm.getCropCapacity()*50;
            farm.expandCropCapacity();
            advanceTurn();
        }
        else throw std::underflow_error("Insufficient funds!");
        }
        catch(const std::exception& e){std::print("{}\n",e.what());}

    }
    void Player::expandFarmland(){
        try{
        if(score >= farm.getFarmCapacity()*10 && balance >= farm.getFarmCapacity()*50){
            balance-=farm.getFarmCapacity()*50;
            farm.expandFarmCapacity();
            advanceTurn();
        }
        else throw std::underflow_error("Insufficient funds!");
        }
        catch(const std::exception& e){std::print("{}\n",e.what());}
    }
    void Player::sowPlant(int seedId){
        try{
            farm.addSeed(seedId);
            barn.remove(seedId,1);
            advanceTurn();
        }
        catch(const std::exception& e){
            std::print("{}", e.what());
        }
    }
    void Player::addAnimal(int animalId){
        try{
            farm.addAnimal(animalId);
            barn.remove(animalId,1);
            advanceTurn();
        }
        catch(const std::exception& e){
            std::print("{}",e.what());
        }
         
    }
    void Player::harvest(){
        try{
            for(const auto& plant:farm.getCropland()){
                if(plant.currentCycle==plant.requiredCycles){
                    barn.add(toID(plant.product), 1);
                }
            }
            for(const auto& animal:farm.getFarmland()){
                if(animal.currentCycle==animal.requiredCycles){
                    barn.add(toID(animal.product), 1);
                }
            }
            farm.harvestPlants();
            farm.harvestAnimals();
            advanceTurn();
        }
        catch(const std::exception& e){std::print("{}\n",e.what());}
    }
    void Player::openMarketCatalog(const Market& market)const{
        market.info();
    }
    void Player::buyItem(Market& market, int productId, int quantity){
        try{
            if(market.getPrice(productId) <= balance){
                balance-=market.getPrice(productId)*quantity;
                market.remove(productId, quantity);
                barn.add(productId, quantity);
                advanceTurn();
            }else throw std::underflow_error("Insufficient funds!");
        }
        catch(const std::exception& e){ std::print("{}\n",e.what()); }
    }
    void Player::sellItem(Market& market, int productId, int quantity){
        try{
            balance+=market.getPrice(productId)*quantity;
            market.add(productId, quantity);
            barn.remove(productId, quantity);
            advanceTurn();
        }
        catch(const std::exception& e){std::print("{}\n",e.what());}
    }
    void Player::showTaskBoard(const TaskBoard& taskBoard)const{
        taskBoard.showInfo();
    }
    
    void Player::advanceTurn() {
        currentCycles++;
        farm.advanceCycle(); 
    }
    void Player::completeTask(TaskBoard& taskBoard, int taskId){
        try{
            Task task=taskBoard.getTask(taskId);
            Products requiredProd = task.requiredProduct;
            barn.remove(toID(requiredProd), task.requiredQuantity);
            balance += task.rewardBalance;
            score += task.rewardScore;
            taskBoard.remove(taskId);
            advanceTurn();
        }
        catch(const std::exception& e){ std::print("{}\n", e.what()); }
    }
    std::strong_ordering Player::operator<=> (const Player& other)const{
        if(auto cmp = score <=> other.score; cmp!=0){
            return cmp;
        }
        if(auto cmp = balance <=> other.balance; cmp!=0){
            return cmp;
        }
        return other.id <=> id;

    }