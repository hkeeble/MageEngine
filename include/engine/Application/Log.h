#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>

#define LOG_FILE "Log.txt"

void log(std::string data);
void closeLog();

#endif
