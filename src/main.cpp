#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <format>

int main(int argc, char *argv[])
{
    if (argc <= 1)
        std::clog << "GUI not implemented yet" << std::endl;

    std::vector<std::string> comandArguments(argv, argv + argc);
    std::map<std::string, std::function<void()>> command_actions;
    

    // Command register
    command_actions["connect"] = [comandArguments]() {
        //FtpClient.connect();
        return 1;
    };

    // Check command
    if (comandArguments.size() > 1) {
        std::string command = comandArguments[1];
        auto it = command_actions.find(command);
        if (it != command_actions.end()) {
            it->second(); // execute command
        } else {
            std::cerr << "Unknown command: " << command << std::endl;
            std::cerr << "Available commands: ";
            for (const auto& [key, _] : command_actions) {
                std::cerr << key << " ";
            }
            std::cerr << std::endl;
            return 1;
        }
    }

    return 0;
}