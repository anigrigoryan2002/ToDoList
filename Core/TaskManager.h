#pragma once
#include "Task.h"
#include <vector>

class TaskManager
{
public:
    bool addTask(const std::string& name);
    bool removeTask(const std::string& name);
    bool completeTask(const std::string& name);
    std::vector<Task> listTasks() const;
    int tasksCount() const;
private:
    std::vector<Task> tasks;
};
