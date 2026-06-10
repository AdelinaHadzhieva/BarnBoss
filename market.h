#pragma once
#include "products.h"
#include <map>
#include <print>
struct ProductDetails{
    int quantity;
    int price;
};

class Market{
    std::map<Products, ProductDetails> market;
    public:
    Market();
    void info()const;
};