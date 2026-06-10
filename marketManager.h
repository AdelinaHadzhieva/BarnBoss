#pragma once
#include "user.h"
#include "market.h"
class MarketManager:public User{
    private:

    MarketManager();

    MarketManager(const MarketManager&)= delete;
    MarketManager& operator=(const MarketManager&) = delete;
    public:
    static MarketManager& getInstance() {
        static MarketManager instance;
        return instance;
    }
    void profileInfo()const override;
    void openMarketCatalog(const Market& market)const;
    void restock(const Market& market,int productId, int quantity);
    void changePrice(const Market& market,int productId, int newPrice);
};
