#pragma once
#include <string>
#include "Command.h"
#include "TaskManager.h"
#include "CommandParser.h"
Command* createCommand(
    const std::string& cmd,
    TaskManager& taskManager,
    const std::string& name,
    CommandParser& parser
);
