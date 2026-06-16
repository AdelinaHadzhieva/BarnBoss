#include "marketManager.h"
bool MarketManager::MarketManagerExists=false;

MarketManager::MarketManager(const std::string& username,const std::string& password):
User(username,password) {
    MarketManagerExists=true;
}

int MarketManager::getID()const{
    return id;
}
void MarketManager::setName(const std::string& userName){
    username = userName;
}


void  MarketManager::profileInfo()const {
    std::print("Id: {}\nUsername: {}\nType: Market Manager\n", id, username);
}
void MarketManager::openMarketCatalog(const Market& market)const{
    market.info();
}
void MarketManager::restock( Market& market,int productId, int quantity){
    try{
    if(productId>0 && productId<market.size()){
       market.add(productId, quantity);
    }
    else throw std::invalid_argument("This product ID does't exist!");
    }
    catch(const std::invalid_argument& e){
        std::print("{}\n",e.what());
    }
}
void MarketManager::changePrice(Market& market,int productId, int newPrice){
    try{
    if(productId>0 && productId<market.size()){
        market.setPrice(productId,newPrice);
    }
    else throw std::invalid_argument("This product ID does't exist!");
    }
    catch(const std::invalid_argument& e){
        std::print("{}\n",e.what());
    }

}