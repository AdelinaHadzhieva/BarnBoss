#pragma once
#include <utility>
#include <vector>
class Barn{
public:
enum class Products{
    Wheat,
    Corn,
    Egg,
    Milk,
    WheatSeed,
    CornSeed,
    Chicken,
    Cow
}
private:
std::vector<std::pair<Products,int>> barn;

};