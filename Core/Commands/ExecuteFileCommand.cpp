#include "ExecuteFileCommand.h"
#include <fstream>
#include <sstream>
#include <filesystem>
ExecuteFileCommand::ExecuteFileCommand(CommandParser& commandParser, const std::string& filePath)
    : commandParser(commandParser), filePath(filePath) {}

std::string ExecuteFileCommand::execute() {
    std::ifstream file(filePath);

    if (!file.is_open())
        return "Error: Cannot open file " + filePath;

    std::string line;
    std::string output;

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        output += commandParser.execute(line) + "\n";
    }

    return output;
}
