#pragma once
#include "user.h"
#include "market.h"
class MarketManager:public User{
    private:
    static bool MarketManagerExists;

    public:
    MarketManager(const std::string& username,const std::string& password);
    static MarketManager& getInstance();
    int getID()const;
    const std::string& getName()const;
    void setName(const std::string& userName);
    

    void profileInfo()const override;
    void openMarketCatalog(const Market& market)const;
    void restock( Market& market,int productId, int quantity);
    void changePrice( Market& market,int productId, int newPrice);
};
