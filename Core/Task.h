#pragma once
#include <string>

class Task {
public:
    Task(const std::string& name);
    std::string getName() const;
    bool isCompleted() const;
    void complete();
private:
    std::string name;
    bool completed;
};
