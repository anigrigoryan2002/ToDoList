#pragma once
#include <string>

class Task {
public:
    Task(const std::string& name);
    std::string getName() const;
    bool isCompleted() const;
    void complete();
    void uncomplete();
    void setCompleted(bool completed);
private:
    std::string name;
    bool completed;
};
