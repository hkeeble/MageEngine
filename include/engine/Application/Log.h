#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>

#define LOG_FILE "Log.txt"

namespace MageEngine
{
    void log(std::string data);
    void closeLog();
}
#endif
