#pragma once
#include <vector>
enum class Plants{  WheatSeed, CornSeed };
enum class Animals { Chicken, Cow};
struct Plant{
    int id;
    Plants name;
    int price;
    int requiredCycles;
    int currentCycles;
    Products product;
}
struct Animal{
    int id;
    Animals name;
    int price;
    int requiredCycles;
    int currentCycles;
    Products product;
}
class Farm{
    std::vector<Seed> cropland;
    std::vector<Animal> farmland;
    int croplandCapacity;
    int farmlandCapacity;
    public:
    Farm();
    int getCropCapacity()const;
    int getFarmCapacity()const;
    int getCropSize()const;
    int getFarmSize()const;
};