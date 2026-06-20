#pragma once
#include "user.h"
#include "../boards/taskBoard.h"

class TaskManager:public User{
    private:
    static bool TaskManagerExists;

    public:
    TaskManager(const std::string& username,const std::string& password);
    
    void profileInfo()const override;
    
    int getID()const;
    void setName(const std::string& userName);
    void showTasks(const TaskBoard& taskBoard)const;
    void addTask(TaskBoard& taskBoard, Products requiredProduct, int quantity,int rewardBalance,int rewardScore);
    void removeTask(TaskBoard& taskBoard, int taskId);

};