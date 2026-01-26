#pragma once
#include "../Command.h"
#include "../TaskManager.h"

class RemoveTaskCommand: public Command
{
public:
    RemoveTaskCommand(TaskManager &manager, const std::string &name);
    std::string execute() override;
private:
    TaskManager& taskManager;
    std::string taskName;
};
