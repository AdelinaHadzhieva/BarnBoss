#include "restockCommand.h"

RestockCommand::RestockCommand( MarketManager& marketManager,Market& market, int id, int qty)
:marketManager(marketManager),market(market), productId(id),quantity(qty){}

void RestockCommand::execute(){
    marketManager.restock(market, productId, quantity);
}