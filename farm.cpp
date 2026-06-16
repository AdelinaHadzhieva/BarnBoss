#include "farm.h"

Farm::Farm():croplandCapacity(3),farmlandCapacity(3){}

int Farm::getCropCapacity()const{
    return croplandCapacity;
}
int Farm::getFarmCapacity()const{
    return farmlandCapacity;
}
int Farm::getCropSize()const{
    return cropland.size();
}
int Farm::getFarmSize()const{
    return farmland.size();
}
void Farm::advanceCycle() {
    for (auto& plant : cropland) {
        if(plant.currentCycle < plant.requiredCycles)
            plant.currentCycle++;
    }
    
    for (auto& animal : farmland) {
        if(animal.currentCycle < animal.requiredCycles)
            animal.currentCycle++;
    }
}

void Farm::expandFarmCapacity(){
    
    farmlandCapacity++;
}

void Farm::expandCropCapacity(){
    croplandCapacity++;
}

void Farm::addSeed(int seedId){
    if(croplandCapacity<=getCropSize())throw std::overflow_error("Cropland is full. Try expanding or harvesting!\n");
    if(seedId==1){
        cropland.emplace_back(1, Plants::WheatSeed, 10, 3, Products::Wheat);
    }
    else if(seedId==2){
        cropland.emplace_back(2, Plants::CornSeed, 15, 4, Products::Corn);
    }
}
void Farm::addAnimal(int animalId){
    if(farmlandCapacity<=getFarmSize())throw std::overflow_error("Farmland is full. Try expanding or harvesting!\n");
    if(animalId==3){
        farmland.emplace_back(3, Animals::Chicken, 25, 3, Products::Egg);
    }
    if(animalId==4){
        farmland.emplace_back(4, Animals::Cow, 50, 5, Products::Milk);
    }

}
const std::vector<Plant>& Farm::getCropland()const{
    return cropland;
}
const std::vector<Animal>& Farm::getFarmland()const{
    return farmland;
}
void Farm::harvestPlants(){
    std::erase_if(cropland, [](const Plant& plant){return plant.currentCycle==plant.requiredCycles;});
}
void Farm::harvestAnimals(){
    std::erase_if(farmland, [](const Animal& animal){return animal.currentCycle==animal.requiredCycles;});
}
void Farm::info()const{
    std::print("FarmLand Capacity: {}\nCropLand Capacity: {}\nFarmLand:",farmlandCapacity, croplandCapacity);//to do
}