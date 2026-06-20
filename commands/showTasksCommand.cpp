#include "showTasksCommand.h"
ShowTasksCommand::ShowTasksCommand(const TaskBoard& taskBoard):taskBoard(taskBoard){}
    void ShowTasksCommand::execute(){
        taskBoard.showInfo();
    }