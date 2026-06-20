#include "changePriceCommand.h"
ChangePriceCommand::ChangePriceCommand( MarketManager& marketManager,Market& market, int id, int price)
:marketManager(marketManager),market(market), productId(id),price(price){}

void ChangePriceCommand::execute(){
    marketManager.changePrice(market, productId, price);
}