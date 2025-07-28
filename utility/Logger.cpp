#include "Logger.h"
using namespace mylogger::utility;
#include <time.h>
#include <string.h>
#include <stdexcept>
#include <iostream>

Logger *Logger::m_instance = nullptr;

const char *Logger::s_level[LEVEL_COUNT] = {
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "FATAL"
};

Logger::Logger() // 构造函数
{

}

Logger::~Logger() // 虚构函数
{

}

Logger *Logger::instance() // 获取实例对象
{
    if (m_instance == NULL)
    {
        m_instance = new Logger();
    }
    return m_instance;
}

void Logger::open(const std::string &filename)
{
    m_filename = filename;
    m_fout.open(filename, std::ios::app);
    if (m_fout.fail())
    {
        throw std::logic_error("open file failed" + filename);
    }
}

void Logger::close(const std::string &filename)
{
    m_fout.close();
}

void Logger::log(Level level, const char *file, int line, const char *format, ...)
{
    if (m_fout.fail())
    {
        throw std::logic_error("open file failed " + m_filename);
    }

    time_t ticks = time(NULL); // 返回时间戳
    tm *ptm = localtime(&ticks);
    char timestamp[32];
    memset(timestamp, 0, sizeof(timestamp));
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", ptm); // format传入时间输出格式

    std::cout << timestamp << std::endl;
}