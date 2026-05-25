#include "farm.h"

Farm::Farm():croplandCapacity(3),farmlandCapacity(3){}

int getCropCapacity()const{
    return croplandCapacity;
}
int getFarmCapacity()const{
    return farmlandCapacity;
}