#include "openMarketCatalogCommand.h"
OpenMarketCatalogCommand::OpenMarketCatalogCommand(const Market& market):market(market){}
void OpenMarketCatalogCommand::execute(){
    market.info();
}