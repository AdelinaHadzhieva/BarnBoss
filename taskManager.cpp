#include "taskManager.h"
void TaskManager::showTasks(const TaskBoard& taskBoard)const{
    taskBoard.showInfo();
    }
void TaskManager::addTask(TaskBoard& taskBoard, Products requiredProduct,
     int quantity, int rewardBalance, int rewardScore){
        taskBoard.add(requiredProduct, quantity, rewardBalance, rewardScore);
}
    
void TaskManager::removeTask(TaskBoard& taskBoard,int taskId){
    taskBoard.remove(taskId);
    
}