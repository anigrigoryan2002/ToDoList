#include "CompleteTaskCommand.h"

CompleteTaskCommand::CompleteTaskCommand(TaskManager &manager, const std::string &name):taskManager(manager), taskName(name) {}

std::string CompleteTaskCommand::execute(){
    if(taskManager.completeTask(taskName)) {
        return "Task '" + taskName + "' completed";
    }
    return "Task '" + taskName + "' not found";
}
