#pragma once

#include <string>
class Logger
{
public:
    enum class LogType{ Error, Warning, Info };
    static void logError(const std::string& msg);
    static void logWarning(const std::string& msg);
    static void logInfo(const std::string& msg);

private:
    static std::string _txtLogFormatting(std::string_view msg, LogType type);
    static std::string_view _typeToString(LogType type);  
};
