#pragma once
#include <map>
#include "products.h"
class Barn{
private:
    std::map<Products,int> barn;
public:
    Barn();
    void info()const;
};