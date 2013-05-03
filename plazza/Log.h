/*
** Log.h for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 15:10:46 2013 maxime ginters
** Last update Wed Apr 17 13:24:02 2013 maxime ginters
*/

#ifndef LOG_H_
# define LOG_H_

#include <fstream>
#include "Mutex.h"
#include "Singleton.hpp"

#define LOG_FILE "output.log"
#define ERROR_FILE "error.log"

class Log : public Singleton<Log>
{
public:
    Log();
    ~Log();

    bool initialize();

    void out(const char* str, ...);
    void error(const char* str, ...);

private:
    std::ofstream _stream;
    Mutex _streamMutex;
    std::ofstream _error;
    Mutex _errorMutex;
};

#define sLog Log::instance()

#endif /* !LOG_H_ */
