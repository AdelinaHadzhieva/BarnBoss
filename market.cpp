#include "market.h"


Market::Market() {
    
    market[Products::Wheat] = {20, 15};
    market[Products::Corn] = {20, 20};
    market[Products::Egg] = {15, 30};
    market[Products::Milk] = {10, 60};
    market[Products::WheatSeed] = {20, 10};
    market[Products::CornSeed] = {20, 15};
    market[Products::Chicken] = {10, 25};
    market[Products::Cow] = {5, 50};
}

int Market::getQty(int id)const{
    return market[productKey(id)].quantity;
}
int Market::getPrice(int id)const{return market[productKey(id)].price;}

void Market::setPrice(int id, int newPrice){ 
    market[productKey(id)].price = newPrice;
}

void Market::info() const {
    std::print("=== MARKET CATALOG ===");
    for(const auto& [key, value] : market) {
        std::print("{}     |Quantity: {}     |Price: {}\n", toString(key), value.quantity, value.price);
    }
}
void Market::add(int productId, int quantity){
    if(quantity>0 ){
        if( productId>=0 && productId < market.size()){
            market[productKey(productId)].quantity+=quantity;
        }
        else throw std::out_of_range("This product ID doesn't exist!\n");
    }
    else throw std::out_of_range("You can't add negative quantity to market!\n");
}
void Market::remove(int productId, int quantity){
    if(productId>=0 && productId < market.size()){
        if(market[productKey(productId)].quantity > quantity)
            market[productKey(productId)].quantity -= quantity;
        else throw std::underflow_error("The quantity of this product is 0 or less than you want!\n");
    }
    else throw std::out_of_range("This product ID doesn't exist!\n");
}