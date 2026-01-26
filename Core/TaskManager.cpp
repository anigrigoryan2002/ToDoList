#include "TaskManager.h"

bool TaskManager::addTask(const std::string& name) {
    for(const auto& t : tasks) {
        if(t.getName() == name) return false;
    }
    tasks.emplace_back(name);
    return true;
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
int TaskManager::pendingTasksCount() const {
    int count = 0;
    for(const auto& t : tasks) {
        if(!t.isCompleted())
            count++;
    }
    return count;
}
bool TaskManager::setCompleted(const std::string& name, bool completed) {
    for (auto& t : tasks) {
        if (t.getName() == name) {
            t.setCompleted(completed);
            return true;
        }
    }
    return false;
}

std::vector<Task> TaskManager::listTasks() const { return tasks; }
int TaskManager::tasksCount() const { return tasks.size();
}
