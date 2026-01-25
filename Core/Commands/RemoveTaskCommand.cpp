#include "RemoveTaskCommand.h"

RemoveTaskCommand::RemoveTaskCommand(TaskManager &manager, std::string &name): taskManager(manager), taskName(name) {}

std::string RemoveTaskCommand::execute() {
    return taskManager.removeTask(taskName) ? "Task removed" : "Task not found";
}
