#pragma once
#include "iCommand.h"
#include "player.h"
class BuyItemCommand:public ICommand{
    Player& player;
    Market& market;
    int id;
    int qty;
    public:
    BuyItemCommand(Player& player,Market& market, int id, int qty);
    void execute()override;
};

class SellItemCommand:public ICommand{
    Player& player;
    Market& market;
    int id;
    int qty;
    public:
    SellItemCommand(Player& player,Market& market, int id, int qty);
    void execute()override;
};