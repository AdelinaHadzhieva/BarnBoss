#pragma once
#include "user.h"
#include "taskBoard.h"

class TaskManager:public User{
    private:
    TaskManager();
    TaskManager(const TaskManager&)= delete;
    TaskManager& operator=(const TaskManager&) = delete;

    public:
    static TaskManager& getInstance() {
        static TaskManager instance;
        return instance;
    }
    void profileInfo()const override;
    void showTasks(const TaskBoard& taskBoard)const;
    void addTask(TaskBoard& taskBoard);
    void removeTask(TaskBoard& taskBoard);

};