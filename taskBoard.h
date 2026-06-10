#pragma once
#include <vector>
#include "products.h"

struct Task{
    static int idCounter;
    int id;
    Products requiredProduct;
    int requiredQuantity;
    int rewardBalance;
    int rewardScore;

};
class TaskBoard{
    std::vector<Task> taskBoard;
    public:
    TaskBoard();
    void showInfo()const;
};