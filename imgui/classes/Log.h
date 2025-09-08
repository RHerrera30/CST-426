#pragma once
#include <string>
#include <vector>

class Log
{
    public:
    enum logLevel
    {
        INFO,
        WARNING,
        ERROR
    };

    static void writeToFile(const std::string& logInfo, logLevel level);
    static const std::vector<std::string>& getMessages();

    static std::vector<std::string> messages;
};