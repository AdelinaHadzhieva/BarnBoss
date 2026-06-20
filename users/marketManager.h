#pragma once
#include "user.h"
#include "../storage/market.h"
#include <fstream>
class MarketManager:public User{
    private:
    static bool MarketManagerExists;

    public:
    MarketManager(const std::string& username,const std::string& password);
    
    int getID()const;
    void setName(const std::string& userName);
    void profileInfo()const override;
    void openMarketCatalog(const Market& market)const;
    void restock( Market& market,int productId, int quantity);
    void changePrice( Market& market,int productId, int newPrice);

    void save(std::ofstream& out) const;
    void load(std::ifstream& in);
};
