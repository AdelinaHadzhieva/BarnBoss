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

void Market::info() const {
    for(const auto& [key, value] : market) {
        std::print("{}      {}      {}\n", toString(key), value.quantity, value.price);
    }
}