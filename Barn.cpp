
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
    std::print("Wheat:{}\n",barn.at(Products::Wheat));
    std::print("Corn:{}\n",barn.at(Products::Corn));
    std::print("Egg:{}\n",barn.at(Products::Egg));
    std::print("Milk:{}\n",barn.at(Products::Milk));
    std::print("WheatSeed:{}\n",barn.at(Products::WheatSeed));
    std::print("CornSeed:{}\n",barn.at(Products::CornSeed));
    std::print("Chicken:{}\n",barn.at(Products::Chicken));
    std::print("Cow:{}\n",barn.at(Products::Cow));
}
    