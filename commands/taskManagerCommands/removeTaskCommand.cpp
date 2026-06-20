#include "removeTaskCommand.h"
RemoveTaskCommand::RemoveTaskCommand(TaskManager& taskManager,TaskBoard& taskBoard, int id)
:taskManager(taskManager), taskBoard(taskBoard), id(id){}

    void RemoveTaskCommand::execute(){
        taskManager.removeTask(taskBoard, id);
    }