/*
** Log.cpp for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 15:10:46 2013 maxime ginters
** Last update Sat Apr 20 16:38:39 2013 fabien casters
*/

#include <ctime>
#include <iostream>
#include <stdarg.h>
#include "Log.h"

Log::Log() : _stream()
{}

Log::~Log()
{
    if (_stream.is_open())
        _stream.close();
}

bool Log::initialize()
{
    try
    {
        _stream.open(LOG_FILE, std::ios_base::out | std::ios_base::trunc);
        _error.open(ERROR_FILE, std::ios_base::out | std::ios_base::trunc);
    }
    catch (std::exception const& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

void Log::out(const char* str, ...)
{
    char buff[4096];
    va_list ap;
    time_t tm;

    va_start(ap, str);
    vsnprintf(buff, 4096, str, ap);
    va_end(ap);

    _streamMutex.lock();
    time(&tm);
    std::string st = ctime(&tm);
    st[st.length() - 1] = ' ';
    _stream << st << ": " << buff << std::endl;
    _streamMutex.unlock();
}

void Log::error(const char* str, ...)
{
    char buff[4096];
    va_list ap;
    time_t tm;

    va_start(ap, str);
    vsnprintf(buff, 4096, str, ap);
    va_end(ap);

    _errorMutex.lock();
    time(&tm);
    std::string st = ctime(&tm);
    st[st.length() - 1] = 0;
    _error << st << ": " << buff << std::endl;
    _errorMutex.unlock();
}
