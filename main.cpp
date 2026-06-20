#include "gameSystem.h"
//g++ -std=c++23 *.cpp storage/*.cpp users/*.cpp boards/*.cpp commands/*.cpp commands/*/*.cpp -o main -I. -I./storage -I./users -I./boards -I./commands -I./commands/marketManagerCommands -I./commands/playerCommands -I./commands/taskManagerCommands
//to compile

int main(){
    GameSystem::getInstance().run();
    return 0;
}