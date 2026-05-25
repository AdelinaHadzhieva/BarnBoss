#pragma once
#include <map>
enum class Products{
    Wheat,
    Corn,
    Egg,
    Milk,
    WheatSeed,
    CornSeed,
    Chicken,
    Cow
};
class Barn{
private:
    std::map<Products,int> barn;
public:
    Barn();
    void info()const;
};