#include "addTaskCommand.h"
AddTaskCommand::AddTaskCommand(TaskManager& taskManager, TaskBoard& taskBoard, Products requiredProduct,
     int quantity,int rewardBalance,int rewardScore)
:taskManager(taskManager), taskBoard(taskBoard), requiredProduct(requiredProduct),
quantity(quantity), rewardBalance(rewardBalance), rewardScore(rewardScore){}

void AddTaskCommand::execute(){
    taskManager.addTask(taskBoard, requiredProduct, quantity, rewardBalance, rewardScore);
}