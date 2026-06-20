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

int Market::size()const{
    return market.size();
}

int Market::getQty(int id)const{
    if(productKey(id).has_value()){
            return market.at(productKey(id).value()).quantity;
        }
        else throw std::out_of_range("Product ID not found!");
    
}
int Market::getPrice(int id)const{
    
        if(productKey(id).has_value()){
            return market.at(productKey(id).value()).price;
        }
        else throw std::out_of_range("Product ID not found!");
    
    
}

void Market::setPrice(int id, int newPrice){ 
    if(productKey(id).has_value())
        market.at(productKey(id).value()).price = newPrice;
    else throw std::out_of_range("Product ID not found!");
}

void Market::info() const {
    std::print("=== MARKET CATALOG ===\n");
    for(const auto& [key, value] : market) {
        std::print("{}. {:<12}  |Quantity: {}     |Price: {}\n",
             toID(key), toString(key), value.quantity, value.price);
    }
}
void Market::add(int productId, int quantity){
    if(quantity>0 ){
        if( productKey(productId).has_value()){
            market.at(productKey(productId).value()).quantity+=quantity;
        }
        else throw std::out_of_range("This product ID doesn't exist!\n");
    }
    else throw std::out_of_range("You can't add negative quantity to market!\n");
}
void Market::remove(int productId, int quantity){
    if(productKey(productId).has_value()){
        if(market.at(productKey(productId).value()).quantity > quantity)
            market.at(productKey(productId).value()).quantity -= quantity;
        else throw std::underflow_error("The quantity of this product is 0 or less than you want!\n");
    }
    else throw std::out_of_range("This product ID doesn't exist!\n");
}

void Market::save(std::ofstream& out) const {
    out << market.size() << "\n";
    for (const auto& [product, details] : market) {
        out << static_cast<int>(product) << " " << details.quantity << " " << details.price << "\n";
    }
}

void Market::load(std::ifstream& in) {
    market.clear();
    int size;
    if (in >> size) {
        for (int i = 0; i < size; ++i) {
            int prodId, qty, price;
            in >> prodId >> qty >> price;
            market[static_cast<Products>(prodId)] = {qty, price};
        }
    }
}