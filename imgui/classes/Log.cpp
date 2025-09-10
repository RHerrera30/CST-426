#include "Log.h"
#include <fstream>
#include <iostream>

    //The log level I will print and write to my file
    Log::logLevel Log::currentLevel;

    //If there is a file already written to, wipe the file clean, otherwise makes a new one. Also sets initial log level.
        void Log::initialize(logLevel level)
    {
        std::ofstream newFile("logFile.txt", std::ios::trunc);
        currentLevel = level;

        newFile << "Logging initialized." << std::endl;
        std::cout << "Logging initialized." << std::endl;
    }

    //Sets level of logs to be written to file and printed to console.
        void Log::setLevel(logLevel level)
    {
        currentLevel = level;

        std::ofstream file("logFile.txt", std::ios::app);
        file << "Updated log level." << std::endl;

        std::cout << "Updated log level. " << std::endl;
    }

    //Writes message to my log file and prints it in the console. Does not write or print if message is not within the log level.
    void Log::write(const std::string& logInfo, logLevel level)
    {
        //String to hold the log level of the incoming log.
        std::string messageLevel;

        //Changes the level of the log
        switch(level)
        {
            case INFO: messageLevel = "[INFO] "; break;
            case WARNING: messageLevel = "[WARNING] "; break;
            case ERROR: messageLevel = "[ERROR] "; break;
        }

        //Check if the log is the current log level, if it isn't then don't print it
        if(level != currentLevel)
        {
            return;
        }

        //Put the log level and log info into one message
        std::string logMessage = messageLevel.append(logInfo);

        //Print my log message to the console
        std::cout << logMessage << std::endl;

        //Open and append to my logFile
        std::ofstream file("logFile.txt", std::ios::app);

        //Check to make sure my file exists
        if (!file) {
            std::cerr << "Failed to open logFile.txt!" << std::endl;
            return;
        }

        //Write my log message to the log file and close the file
        file << logMessage <<std::endl;
        file.close();
    };