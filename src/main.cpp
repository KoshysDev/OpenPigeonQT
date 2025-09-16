#include <iostream>
#include <map>
#include <string>
#include <functional>

int main(int argc, char *argv[])
{
    if (argc <= 1)
        std::clog << "GUI not implemented yet" << std::endl;

    std::map<std::string, std::function<void()>> command_actions;

    return 0;
}