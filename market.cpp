#include "market.h"


Market::Market() {
    
    market.at(Products::Wheat) = {20, 15};
    market.at(Products::Corn) = {20, 20};
    market.at(Products::Egg) = {15, 30};
    market.at(Products::Milk) = {10, 60};
    market.at(Products::WheatSeed) = {20, 10};
    market.at(Products::CornSeed) = {20, 15};
    market.at(Products::Chicken) = {10, 25};
    market.at(Products::Cow) = {5, 50};
}

int Market::size()const{
    return market.size();
}

int Market::getQty(int id)const{
    if(id > 0 && id < market.size()){
            return market.at(productKey(id)).quantity;
        }
        else throw std::out_of_range("Product ID not found");
    
}
int Market::getPrice(int id)const{
    
        if(id > 0 && id < market.size()){
            return market.at(productKey(id)).price;
        }
        else throw std::out_of_range("Product ID not found");
    
    
}

void Market::setPrice(int id, int newPrice){ 
    market.at(productKey(id)).price = newPrice;
}

void Market::info() const {
    std::print("=== MARKET CATALOG ===");
    for(const auto& [key, value] : market) {
        std::print("{}     |Quantity: {}     |Price: {}\n", toString(key), value.quantity, value.price);
    }
}
void Market::add(int productId, int quantity){
    if(quantity>0 ){
        if( productId > 0 && productId <= market.size()){
            market.at(productKey(productId)).quantity+=quantity;
        }
        else throw std::out_of_range("This product ID doesn't exist!\n");
    }
    else throw std::out_of_range("You can't add negative quantity to market!\n");
}
void Market::remove(int productId, int quantity){
    if(productId > 0 && productId <= market.size()){
        if(market.at(productKey(productId)).quantity > quantity)
            market.at(productKey(productId)).quantity -= quantity;
        else throw std::underflow_error("The quantity of this product is 0 or less than you want!\n");
    }
    else throw std::out_of_range("This product ID doesn't exist!\n");
}