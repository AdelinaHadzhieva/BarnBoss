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
}
Products stringToProduct(const std::string& product){
    switch(product) {
        case "Wheat": return Products::Wheat; 
        case "Corn": return Products::Corn; 
        case "Egg": return Products::Egg; 
        case "Milk": return Products::Milk; 
        case "WheatSeed": return Products::WheatSeed; 
        case "CornSeed": return Products::CornSeed;
        case "Chicken": return Products::Chicken; 
        case "Cow": return Products::Cow;
}
Products productKey(int ID){
    return static_cast<Products>(ID);
}