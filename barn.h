#pragma once
#include <map>
#include "products.h"
#include <print>
#include <exception>
class Barn{
private:
    std::map<Products,int> barn;
public:
    Barn();
    void info()const;
    void add(int productID, int quantity);
    void remove(int productID, int qty);
};