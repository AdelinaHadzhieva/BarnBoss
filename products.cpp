#include "products.h"
std::string toString(const Products& product){
        switch(product) {
        case Products::Wheat: return "Wheat"; 
        case Products::Corn: return "Corn"; 
        case Products::Egg: return "Egg"; 
        case Products::Milk: return "Milk"; 
        case Products::WheatSeed: return "Wheat Seed"; 
        case Products::CornSeed: return "Corn Seed";
        case Products::Chicken: return "Chicken"; 
        case Products::Cow: return "Cow";
    }
    return "";
}
int toID(const Products& product){
    switch(product) {
        case Products::Wheat: return 1; 
        case Products::Corn: return 2; 
        case Products::Egg: return 3; 
        case Products::Milk: return 4; 
        case Products::WheatSeed: return 5; 
        case Products::CornSeed: return 6;
        case Products::Chicken: return 7; 
        case Products::Cow: return 8;
    }
    return -1;
}
Products stringToProduct(const std::string& product) {
    if (product == "Wheat") return Products::Wheat;
    if (product == "Corn") return Products::Corn;
    if (product == "Egg") return Products::Egg;
    if (product == "Milk") return Products::Milk;
    if (product == "WheatSeed") return Products::WheatSeed;
    if (product == "CornSeed") return Products::CornSeed;
    if (product == "Chicken") return Products::Chicken;
    if (product == "Cow") return Products::Cow;
    return Products::Wheat;
}
Products productKey(int ID){
    return static_cast<Products>(ID);
}