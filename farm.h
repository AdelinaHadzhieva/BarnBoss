#pragma once
#include <vector>
#include <print>
#include <exception>
#include "products.h"
enum class Plants{  WheatSeed=1, CornSeed=2 };
enum class Animals { Chicken=3, Cow=4};
struct Plant{
    int id;
    Plants name;
    int price;
    int requiredCycles;
    Products product;
};
struct Animal{
    int id;
    Animals name;
    int price;
    int requiredCycles;
    Products product;
};
class Farm{
    std::vector<Plant> cropland;
    std::vector<Animal> farmland;
    int croplandCapacity;
    int farmlandCapacity;
    public:
    Farm();
    int getCropCapacity()const;
    int getFarmCapacity()const;
    int getCropSize()const;
    int getFarmSize()const;
    void expandFarmCapacity();
    void expandCropCapacity();
    void addSeed(int seedId);
    void addAnimal(int animalId);
    void info()const;
};