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
void Farm::addSeed(int seedId){
    if(croplandCapacity<=cropland.size())return;//exception
    if(seedId==1){
        cropland.emplace_back(1,Plants::WheatSeed,10,3,0,Products::Wheat);
    }
    else if(seedId==2){
        cropland.emplace_back(2,Plants::CornSeed,15,4,0,Products::Corn);
    }
}
void Farm::addAnimal(int animalId){
    if(farmlandCapacity<=farmland.size())return;//exception
    if(animalId==3){
        farmland.emplace_back(3,Animals::Chicken,25,3,0,Products::Egg);
    }
    if(animalId==4){
        farmland.emplace_back(3,Animals::Cow,50,5,0,Products::Milk);
    }

}
void Farm::info()const{
    std::print("");//TO DO
}