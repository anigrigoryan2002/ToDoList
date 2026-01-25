#pragma once
#include "TaskManager.h"
#include <string>

class CommandParser
{
public:
    CommandParser(TaskManager& manager);
    std::string execute(const std::string& command);
private:
    TaskManager& taskManager;
};
