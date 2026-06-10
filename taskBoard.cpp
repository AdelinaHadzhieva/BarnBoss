#include "taskBoard.h"

    TaskBoard::TaskBoard(){

        taskBoard.emplace_back(++id, Products::Wheat, 5, 50, 10);
        taskBoard.emplace_back(++id, Products::Milk, 3, 120, 20);
    }
    void showInfo()const{
        for(const auto& task:taskBoard){
            std::print("ID:{}  {}x",id,requiredQuantity);
            switch(task.requiredProduct){
                case Wheat: std::print("Wheat"); break;
                case Corn: std::print("Corn"); break;
                case Egg: std::print("Egg"); break;
                case Milk: std::print("Milk"); break;
                case WheatSeed: std::print("WheatSeed"); break;
                case CornSeed: std::print("CornSeed"); break;
                case Chicken: std::print("Chicken"); break;
                case Cow: std::print("Cow"); break;
            }
        }  
    }