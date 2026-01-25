#pragma once
#include "../Command.h"
#include "../TaskManager.h"
#include <string>

class AddTaskCommand : public Command {
public:
    AddTaskCommand(TaskManager& manager, const std::string& name);
    std::string execute() override;
private:
    TaskManager& taskManager;
    std::string taskName;
};
