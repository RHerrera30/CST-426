#include "Application.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Log {      
  public:
    enum logLevel
    {
        INFO,
        WARNING,
        ERROR
    };
    
    void writeToFile(std::string logInfo)
    {
            fstream MyFile("logFile.txt", std::ios::app);

            MyFile << logInfo;

            MyFile.close();
    };

};