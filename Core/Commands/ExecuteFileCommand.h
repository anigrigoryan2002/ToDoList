#pragma once

#include "../Command.h"
#include "../CommandParser.h"
#include <string>

class ExecuteFileCommand : public Command {
public:
    ExecuteFileCommand(CommandParser& parser,
                       const std::string& filePath);

    std::string execute() override;

private:
    CommandParser& commandParser;
    std::string filePath;
};
