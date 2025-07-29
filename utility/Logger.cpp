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

    const char *fmt = "%s %s %s:%d";
    int size = snprintf(NULL, 0, fmt, timestamp, s_level[level], file, line);
    if (size > 0)
    {
        char *buffer = new char[size + 1]; // 最后一位\0防止字符串溢出
        memset(buffer, 0, sizeof(buffer));
        snprintf(buffer, size + 1, fmt, timestamp, s_level[level], file, line);
        buffer[size] = '\0';

        std::cout << buffer << std::endl;
        m_fout << buffer;
        delete buffer;
    }
    m_fout.flush();

    // std::cout << timestamp << std::endl;
    // std::cout << file << std::endl;
    // std::cout << line << std::endl;
    // std::cout << format <<std::endl;

}