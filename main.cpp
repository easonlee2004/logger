#include <iostream>

#include "utility/Logger.h"
using namespace mylogger::utility;

int main()
{
    // std::cout << "my log" << std::endl;
    Logger::instance()->open("./test.log");
    Logger::instance()->log(Logger::DEBUG, __FILE__, __LINE__, "Hello world");

    return 0;
}