#pragma once

#include <string>
#include <fstream>


namespace mylogger{
namespace utility{

class Logger
{
public:
    enum Level
    {
        DEBUG = 0,
        INFO,
        WARN,
        ERROR,
        FATAL,
        LEVEL_COUNT
    };

    static Logger *instance(); // 返回单例的指针
    void open(const std::string &filename); // 打开文件
    void close(const std::string &filename); // 关闭文件

    void log(Level level, const char *file, int line, const char *format, ...);
private:
    Logger();
    ~Logger();
private:
    std::string m_filename; // 文件名称字符串
    std::ofstream m_fout; // 输出流
    static const char *s_level[LEVEL_COUNT];
    static Logger *m_instance; // 单例模式入口
};

}
}