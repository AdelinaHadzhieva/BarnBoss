#pragma once 
#include "iCommand.h"
#include "market.h"
class OpenMarketCatalogCommand:public ICommand{
    const Market& market;
    public:
    OpenMarketCatalogCommand(const Market& market);
    void execute()override;
};