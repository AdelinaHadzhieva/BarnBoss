#pragma once
#include "products.h"
#include <map>
#include <print>
#include <stdexcept>
#include <fstream>
struct ProductDetails{
    int quantity;
    int price;
};

class Market{
    std::map<Products, ProductDetails> market;
    public:
    Market();
    void info()const;
    int size()const;
    int getQty(int id)const;
    int getPrice(int id)const;
    void setPrice(int id, int newPrice);
    void add(int productId, int quantity);
    void remove(int productId, int quantity);

    void save(std::ofstream& out) const;
    void load(std::ifstream& in);
};