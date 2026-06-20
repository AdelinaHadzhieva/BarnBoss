#pragma once
#include "iCommand.h"
#include "taskManager.h"
class AddTaskCommand:public ICommand{
    TaskManager& taskManager;
    TaskBoard& taskBoard;
    Products requiredProduct;
    int quantity;
    int rewardBalance;
    int rewardScore;
    public:
    AddTaskCommand(TaskManager& taskManager, TaskBoard& taskBoard, Products requiredProduct, int quantity,int rewardBalance,int rewardScore);
    void execute()override;
};