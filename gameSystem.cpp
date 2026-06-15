#include "gameSystem.h"

GameSystem::GameSystem& getInstance(){
    static GameSystem instance;
    return instance;
}