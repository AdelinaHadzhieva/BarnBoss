
#include "barn.h"
#include <print>
Barn::Barn(){
    barn[Products::Wheat] = 0;
    barn[Products::Corn] = 0;
    barn[Products::Egg] = 0;
    barn[Products::Milk] = 0;
    barn[Products::WheatSeed] = 0;
    barn[Products::CornSeed] = 0;
    barn[Products::Chicken] = 0;
    barn[Products::Cow] = 0;
}
void Barn::info()const{
    std::print("==========\n   BARN   \n==========\n");
    std::print("Wheat:{}\n", barn.at(Products::Wheat));
    std::print("Corn:{}\n", barn.at(Products::Corn));
    std::print("Egg:{}\n", barn.at(Products::Egg));
    std::print("Milk:{}\n", barn.at(Products::Milk));
    std::print("WheatSeed:{}\n", barn.at(Products::WheatSeed));
    std::print("CornSeed:{}\n", barn.at(Products::CornSeed));
    std::print("Chicken:{}\n", barn.at(Products::Chicken));
    std::print("Cow:{}\n", barn.at(Products::Cow));
}

void Barn::add(int productID, int quantity){
    
    if(quantity>0 ){
        if( productID>=0 && productID<barn.size()){
        barn[productKey(productID)]+=quantity;
        else throw std::out_of_range("This product ID doesn't exist!");
    }
    }
    else throw std::out_of_range("You can't add negative quantity to barn!");
}
void Barn::remove(int productID){
    if(productID>=0 && productID<barn.size()){
        if(barn[productKey(productID)].quantity>0)
            barn[productKey(productID)]--;
        else throw std::underflow_error("The quantity of this product is 0!");
    }
    else throw std::out_of_range("This product ID doesn't exist!");
}
    