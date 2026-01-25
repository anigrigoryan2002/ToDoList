#include "Task.h"

Task::Task(const std::string& name): name(name), completed(false) {}

std::string Task::getName() const { return name; }
bool Task::isCompleted() const { return completed; }
void Task::complete() { completed = true; }
