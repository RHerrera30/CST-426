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

    static logLevel currentLevel;

    static void initialize(logLevel level);
    static void setLevel(logLevel level); 
    static void write(const std::string& logInfo, logLevel level); 
};