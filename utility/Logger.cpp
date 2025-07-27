#include "Logger.h"
using namespace mylogger::utility;

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