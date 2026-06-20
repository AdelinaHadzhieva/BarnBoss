#pragma once 
#include "iCommand.h"
#include "taskBoard.h"
class ShowTasksCommand:public ICommand{
    const TaskBoard& taskBoard;
    public:
    ShowTasksCommand(const TaskBoard& taskBoard);
    void execute()override;
};