#include "Logger.hpp"

#include <iostream>
#include <format>
#include <chrono>

std::string_view Logger::_typeToString(LogType type)
{
    switch (type)
    {
    case LogType::Error:
        return "ERROR";
    case LogType::Warning:
        return "WARNING";
    case LogType::Info:
        return "INFO";
    }
    return "UNKNOWN";
}

static std::string utcTimestamp()
{
    using namespace std::chrono;
    const auto now = floor<seconds>(system_clock::now());
    return std::format("{:%Y-%m-%d %H:%M:%S}", now);
}

std::string Logger::_txtLogFormatting(std::string_view msg, LogType type)
{
    return std::format("[{}][{}]: {}\n",
                       utcTimestamp(),
                       _typeToString(type), msg);
}

void Logger::logError(const std::string &msg)
{
    std::cerr << _txtLogFormatting(msg, LogType::Error);
}

void Logger::logWarning(const std::string &msg)
{
    std::clog << _txtLogFormatting(msg, LogType::Warning);
}

void Logger::logInfo(const std::string &msg)
{
    std::cout << _txtLogFormatting(msg, LogType::Info);
}
