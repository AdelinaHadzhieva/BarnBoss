#pragma once
#include <map>
#include "products.h"
#include <print>
#include <exception>
#include <fstream>
class Barn{
private:
    std::map<Products,int> barn;
public:
    Barn();
    void info()const;
    void add(int productID, int quantity);
    void remove(int productID, int qty);

    void save(std::ofstream& out) const;
    void load(std::ifstream& in);
};