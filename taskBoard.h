#pragma once
#include <vector>
#include "products.h"
#include <exception>
#include <print>

struct Task{
    static int idCounter;
    int id;
    Products requiredProduct;
    int requiredQuantity;
    int rewardBalance;
    int rewardScore;
    Task(const Products& product, int quantity, int balance, int score);

};
class TaskBoard{
    std::vector<Task> taskBoard;
    public:
    TaskBoard();
    void showInfo()const;
    const Task& getTask(int ID)const;
    void remove(int id);
    void add(const Products& requiredProduct, int quantity, int rewardBalance, int rewardScore);
};