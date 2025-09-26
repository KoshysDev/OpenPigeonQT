#include <iostream>
#include <map>
#include <functional>
#include <format>

#include "Logger.hpp"

int main(int argc, char *argv[])
{
    if (argc <= 1)
        Logger::logInfo("GUI not implemented yet");

    // === MOVE THIS COMMAND LOGIC OUT LATER ===

    std::vector<std::string> comandArguments(argv, argv + argc);
    std::map<std::string, std::function<void()>> command_actions;

    // Command register
    command_actions["connect"] = [comandArguments]()
    {
        // FtpClient.connect();
        return 1;
    };

    // Check command
    if (comandArguments.size() > 1)
    {
        std::string command = comandArguments[1];
        auto it = command_actions.find(command);
        if (it != command_actions.end())
        {
            it->second(); // execute command
        }
        else
        {
            std::string _cmds{};

            for (const auto &[key, _] : command_actions)
            {
                _cmds += key + " ";
            }

            Logger::logError(
                std::format("Unknown command: {}\nAvailable commands:\n{}", command, _cmds));
            return 1;
        }
    }

    Logger::logInfo("Press ENTER to continue...");
    std::cin.get();
    return 0;
}