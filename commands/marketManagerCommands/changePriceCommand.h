#pragma once
#include "./commands/iCommand.h"
#include "marketManager.h"
class ChangePriceCommand:public ICommand{
    MarketManager& marketManager;
    Market& market;
    int productId;
    int price;
    public:
    ChangePriceCommand(MarketManager& marketManager, Market& market, int id, int price);
    void execute()override;
};