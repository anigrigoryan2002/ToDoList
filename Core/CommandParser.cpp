#include "CommandParser.h"
#include "CommandFactory.h"
#include <sstream>

CommandParser::CommandParser(TaskManager& manager)
    : taskManager(manager) {}

std::string CommandParser::execute(const std::string& input)
{
    std::istringstream iss(input);
    std::string cmd;
    iss >> cmd;

    if(cmd.empty())
        return "";

    // -------------------
    // list_tasks
    if(cmd == "list_tasks") {
        Command* c = createCommand(cmd, taskManager, "", *this);
        std::string r = c->execute();
        delete c;
        return r;
    }

    // -------------------
    // execute_file - batch execution
    if(cmd == "execute_file") {
        std::string flag, filepath;
        iss >> flag;
        std::getline(iss, filepath);

        if(!filepath.empty() && filepath[0]==' ')
            filepath.erase(0,1); // trim leading space

        if(flag != "-file_path" || filepath.empty())
            return "Error: Invalid syntax";

        Command* c = createCommand(cmd, taskManager, filepath, *this);
        if(!c)
            return "Error: Unknown command";

        std::string r = c->execute();
        delete c;
        return r;
    }

    // -------------------
    // add_task / remove_task / complete_task
    std::string flag, name;
    iss >> flag;
    std::getline(iss, name);
    if(!name.empty() && name[0]==' ')
        name.erase(0,1); // trim

    if(flag != "-name") return "Error: Invalid syntax";
    if(name.empty()) return "Error: Task name is empty";

    Command* c = createCommand(cmd, taskManager, name, *this);
    if(!c)
        return "Error: Unknown command";

    std::string r = c->execute();
    delete c;
    return r;
}
