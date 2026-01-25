#pragma once
#include "../Command.h"
#include "../TaskManager.h"
#include <string>

class ListTasksCommand : public Command {
public:
    ListTasksCommand(TaskManager& manager);
    std::string execute() override;

private:
    TaskManager& taskManager;
};
