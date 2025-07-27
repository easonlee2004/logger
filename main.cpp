#include <iostream>

#include "utility/Logger.h"
using namespace mylogger::utility;

int main()
{
    // std::cout << "my log" << std::endl;
    Logger::instance()->open("./test.log");

    return 0;
}