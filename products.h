#pragma once

#include <string>
enum class Products{
    Wheat=1,
    Corn,
    Egg,
    Milk,
    WheatSeed,
    CornSeed,
    Chicken,
    Cow
};
std::string toString(const Products& product);
int toID(const Products& product);
Products productKey(int ID);
