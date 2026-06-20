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
    std::print("=== TASK BOARD ===\n");
    for(const auto& task: taskBoard){
        std::print("ID:{}  {}x{:<8}  -> Reward:  {} balance + {} score\n",
             task.id , task.requiredQuantity, toString(task.requiredProduct), task.rewardBalance, task.rewardScore);
    }  
}

const Task& TaskBoard::getTask(int ID)const{
    for(const auto& task:taskBoard){
        if(task.id == ID)return task;
    }
    throw std::invalid_argument("This task ID does't exist!");
}

void TaskBoard::add(const Products& requiredProduct,
     int quantity, int rewardBalance, int rewardScore){
        taskBoard.emplace_back(requiredProduct, quantity, rewardBalance, rewardScore);
}
    
void TaskBoard::remove(int taskId){
    try{
        
        int removedCount = std::erase_if(taskBoard, [taskId](const Task& task){
            return task.id == taskId;
        });
        if(removedCount == 0)
         throw std::invalid_argument("This task ID doesn't exist!");
    }
    catch(const std::invalid_argument& e){
        std::print("{}\n",e.what());
    }
    
}