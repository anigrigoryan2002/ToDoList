#include "CommandFactory.h"
#include "Commands/AddTaskCommand.h"
#include "Commands/RemoveTaskCommand.h"
#include "Commands/CompleteTaskCommand.h"
#include "Commands/ListTasksCommand.h"

Command* createCommand(
    const std::string& cmd,
    TaskManager& taskManager,
    const std::string& name
    ) {
    if(cmd == "add_task")
        return new AddTaskCommand(taskManager, name);

    if(cmd == "remove_task")
        return new RemoveTaskCommand(taskManager, name);

    if(cmd == "complete_task")
        return new CompleteTaskCommand(taskManager, name);

    if(cmd == "list_tasks")
        return new ListTasksCommand(taskManager);

    return nullptr;
}
