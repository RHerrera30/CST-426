#pragma once
#include <fstream>

namespace ClassGame {
    void GameStartUp();
    void RenderGame();
    void EndOfTurn();
}

class Log
{
    public:
    void writeToFile(const std::string logInfo);
};
