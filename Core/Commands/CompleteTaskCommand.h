#pragma once
#include "../Command.h"
#include "../TaskManager.h"
#include <string>

class CompleteTaskCommand: public Command
{
public:
    CompleteTaskCommand(TaskManager &manager, const std::string& name);
    std::string execute() override;
private:
    TaskManager& taskManager;
    std::string taskName;
};
