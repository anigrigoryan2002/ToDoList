#include "CompleteTaskCommand.h"

CompleteTaskCommand::CompleteTaskCommand(TaskManager &manager, const std::string &name):taskManager(manager), taskName(name) {}

std::string CompleteTaskCommand::execute(){
    return taskManager.completeTask(taskName) ? "Task completed" : "Task not found";
}
