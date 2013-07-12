#include "engine/Application/Log.h"

std::ofstream logFile(LOG_FILE);

void log(std::string data)
{
    logFile << data;
    logFile.flush();
}

void closeLog()
{
    logFile << "Closing log stream...\n";
    logFile.close();
}
