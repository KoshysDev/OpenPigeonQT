#pragma once

#include <iostream>
class Logger
{
public:
    static void LogError(const std::string& msg);
    static void LogWarning(const std::string& msg);
    static void LogInfo(const std::string& msg);
};
