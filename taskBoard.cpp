#include "taskBoard.h"

int Task::idCounter=0;
    Task::Task(const Products& product, int quantity, int balance, int score)
    :requiredProduct(product), requiredQuantity(quantity), 
    rewardBalance(balance), rewardScore(score), id(++idCounter){}

    TaskBoard::TaskBoard(){
        taskBoard.emplace_back( Products::Wheat, 5, 50, 10);
        taskBoard.emplace_back( Products::Milk, 3, 120, 20);
    }
void TaskBoard::showInfo()const{
    std::print("==== TASK BOARD ====")
    for(const auto& task: taskBoard){
        std::print("ID:{}  {}x{}  -> Reward:  {} balance + {} score\n", task.id , task.requiredQuantity, toString(task.requiredProduct), task.rewardBalance, task.rewardScore);
    }  
}

void TaskBoard::add(const Products& requiredProduct,
     int quantity, int rewardBalance, int rewardScore){
        taskBoard.emplace_back(requiredProduct, quantity, rewardBalance, rewardScore);
}
    
void TaskBoard::remove(int taskId){
    try{
        if(taskId < taskBoard.size())
        taskBoard.erase(taskBoard.begin()+taskId);
        else throw std::invalid_argument("This task ID doesn't exist!");
    }
    catch(const std::invalid_argument& e){
        std::print("{}\n",e.what());
    }
    
}