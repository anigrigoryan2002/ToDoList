#include "TaskManager.h"

bool TaskManager::addTask(const std::string& name) {
    for(const auto& t : tasks) {
        if(t.getName() == name) return false;
    }
    tasks.emplace_back(name);
};

bool TaskManager::removeTask(const std::string& name) {
    for(auto it = tasks.begin(); it != tasks.end(); ++it){
        if(it->getName() == name){
            tasks.erase(it);
            return true;
        }
    }
    return false;
}

bool TaskManager::completeTask(const std::string& name) {
    for(auto& t : tasks) {
        if(t.getName() == name) {
            t.complete();
            return true;
        }
    }
    return false;
}

std::vector<Task> TaskManager::listTasks() const { return tasks; }
int TaskManager::tasksCount() const { return tasks.size();
}
