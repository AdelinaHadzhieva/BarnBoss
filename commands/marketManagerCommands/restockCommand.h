#pragma once
#include "iCommand.h"
#include "marketManager.h"
class RestockCommand:public ICommand{
    MarketManager& marketManager;
    Market& market;
    int productId;
    int quantity;
    public:
    RestockCommand( MarketManager& marketManager, Market& market, int id, int qty);
    void execute()override;
};