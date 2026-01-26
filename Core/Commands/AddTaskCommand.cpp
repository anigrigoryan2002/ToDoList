#include "AddTaskCommand.h"

AddTaskCommand::AddTaskCommand(TaskManager& manager, const std::string& name)
    : taskManager(manager), taskName(name) {}

std::string AddTaskCommand::execute() {
    return taskManager.addTask(taskName)
    ? "Task '" + taskName + "' added"
    : "Error: Task '" + taskName + "' already exists";
}
