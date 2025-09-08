#include "Log.h"
#include <fstream>
#include <iostream>

//Where I'll store my messages
std::vector<std::string> Log::messages;

    void Log::writeToFile(const std::string& logInfo, logLevel level)
    {
        //String to hold the log level of the incoming log
        std::string messageLevel;

        //Changes the level of the log
        switch(level)
        {
            case INFO: messageLevel = "[INFO] "; break;
            case WARNING: messageLevel = "[WARNING] "; break;
            case ERROR: messageLevel = "[ERROR] "; break;
        }

        //Put the log level and log info into one message
        std::string logMessage = messageLevel.append(logInfo);

        //Store the message in memory.
        messages.push_back(logMessage);

        //Declare my log file and make it appendable
        std::ofstream MyFile("logFile.txt", std::ios::app);

        //Check to make sure my file exists before I try to print to it
        if (!MyFile) {
            std::cerr << "Failed to open logFile.txt!" << std::endl;
            return;
        }

        //Print my log message to the log file
        MyFile << logMessage <<std::endl;

        MyFile.close();

        //Just making sure I made it to the bottom of this method
        std::cout << "writeToFile called";
    };

    const std::vector<std::string>& Log::getMessages()
    {
        return messages;
    }