#include "CommandParser.h"
#include "Command.h"
#include "Commands/AddTaskCommand.h"
#include "Commands/RemoveTaskCommand.h"
#include "Commands/CompleteTaskCommand.h"
#include "Commands/ListTasksCommand.h"

#include <sstream>
#include <memory>

CommandParser::CommandParser(TaskManager& manager): taskManager(manager) {}

std::string CommandParser::execute(const std::string& command) {
    std::istringstream iss(command);
    std::string cmd, flag, name;
    iss >> cmd >> flag >> name;

    std::unique_ptr<Command> cmdObj;
    if(cmd == "add_task"){
        if(flag != "-name" || name.empty()) return "Invalid complete_task syntax";
        cmdObj = std::make_unique<AddTaskCommand>(taskManager, name);
    }else if(cmd == "remove_task") {
        if(flag != "-name" || name.empty()) return "Invalid complete_task syntax";
        cmdObj = std::make_unique<RemoveTaskCommand>(taskManager, name);
    }else if(cmd == "complete_task"){
        if(flag != "-name" || name.empty()) return "Invalid complete_task syntax";
        cmdObj = std::make_unique<CompleteTaskCommand>(taskManager, name);

    }else if(cmd == "list_tasks"){
        cmdObj = std::make_unique<ListTasksCommand>(taskManager);
    }else {
        return "Unknown command";
    }
    return cmdObj->execute();
}
