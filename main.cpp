#include "gameSystem.h"
int main(){
    GameSystem& game = GameSystem::getInstance();
    game.run();
    return 0;
}