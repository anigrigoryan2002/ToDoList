#include "ListTasksCommand.h"

ListTasksCommand::ListTasksCommand(TaskManager& manager) : taskManager(manager) {}

std::string ListTasksCommand::execute() {
    std::string output;
    for(const auto& t : taskManager.listTasks())
        output += t.getName() + (t.isCompleted() ? " [Done]\n" : " [Pending]\n");
    return output.empty() ? "No tasks" : output;
}
