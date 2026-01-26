#include "RemoveTaskCommand.h"

RemoveTaskCommand::RemoveTaskCommand(TaskManager &manager, const std::string &name): taskManager(manager), taskName(name) {}

std::string RemoveTaskCommand::execute() {
    return taskManager.removeTask(taskName)
    ? "Task '" + taskName + "' removed"
    : "Error: Task '" + taskName + "' not found";
}
