#pragma once

#include <string>
#include <optional>
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
std::optional<Products> productKey(int ID);
std::optional<Products> stringToProduct(const std::string& product);
