#pragma once
#include "iCommand.h"
#include "taskManager.h"
class RemoveTaskCommand:public ICommand{
    TaskManager& taskManager;
    TaskBoard& taskBoard;
    int id;
    public:
    RemoveTaskCommand(TaskManager& taskManager,TaskBoard& taskBoard, int id);
    void execute()override;
};