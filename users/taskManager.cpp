#include "taskManager.h"

bool TaskManager::TaskManagerExists=false;

TaskManager::TaskManager(const std::string& username,const std::string& password)
:User(username, password) {
    TaskManagerExists=true;
}
void TaskManager::profileInfo()const {
    std::print("Id: {}\nUsername: {}\nType: Task Manager\n", id, username);
}

int TaskManager::getID()const{
    return id;
}
void TaskManager::setName(const std::string& userName){
    username = userName;
}

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


void TaskManager::save(std::ofstream& out) const { out << username << " " << password << "\n"; }
void TaskManager::load(std::ifstream& in) { in >> username >> password; }