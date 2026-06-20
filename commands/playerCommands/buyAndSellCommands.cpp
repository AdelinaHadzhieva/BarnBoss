#include "buyAndSellCommands.h"
BuyItemCommand::BuyItemCommand(Player& player,Market& market, int id, int qty)
:player(player), market(market), id(id), qty(qty){}
    void BuyItemCommand::execute(){
        player.buyItem(market, id, qty);
    }
SellItemCommand::SellItemCommand(Player& player, Market& market, int id, int qty)
    :player(player), market(market), id(id), qty(qty){}
    void SellItemCommand::execute(){
        player.sellItem(market, id, qty);
    }