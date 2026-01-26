#include "CommandParser.h"
#include "Command.h"
#include "Commands/AddTaskCommand.h"
#include "Commands/RemoveTaskCommand.h"
#include "Commands/CompleteTaskCommand.h"
#include "Commands/ListTasksCommand.h"
#include "CommandFactory.h"
#include <sstream>
#include <memory>

CommandParser::CommandParser(TaskManager& manager): taskManager(manager) {}

std::string CommandParser::execute(const std::string& input) {
    std::istringstream iss(input);
    std::string cmd, flag, name;
    iss >> cmd >> flag >> name;

    if(cmd != "list_tasks" && (flag != "-name" || name.empty()))
        return "Invalid syntax";

    Command* command = createCommand(cmd, taskManager, name);
    if(!command)
        return "Unknown command";

    std::string result = command->execute();
    delete command;

    return result;
}
