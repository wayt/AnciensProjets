/*
** log.c for ex08 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_j01-2016-ginter_m/ex08
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 09 22:35:14 2013 maxime ginters
** Last update Wed Jan 09 23:10:24 2013 maxime ginters
*/

#include <time.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"

static enum LogLevel log_level = Error;
static FILE* log_file;

enum LogLevel get_log_level()
{
    return log_level;
}

enum LogLevel set_log_level(enum LogLevel val)
{
    if (val <= Debug)
        log_level = val;
    return log_level;
}

int set_log_file(char const* file)
{
    FILE* tmp = NULL;

    tmp = fopen(file, "a");
    if (!tmp)
        return 1;
    if (log_file && log_file != stderr && log_file != stdout)
        fclose(log_file);
    log_file = tmp;
    return 0;
}

int close_log_file()
{
    log_to_stderr();
    if (!log_file)
        return 0;
    if (log_file == stderr || log_file == stdout)
        return 0;
    if (fclose(log_file) != 0)
        return 1;
    return 0;
}

int log_to_stdout()
{
    if (log_file && log_file != stderr && log_file != stdout)
        if (fclose(log_file) != 0)
            return 1;
    log_file = stdout;
    return 0;
}

int log_to_stderr()
{
    if (log_file && log_file != stderr && log_file != stdout)
        if (fclose(log_file) != 0)
            return 1;
    log_file = stderr;
    return 0;
}

void log_msg(enum LogLevel val, char const* fmt, ...)
{
    if (val > log_level)
        return;
    if (!log_file)
        log_file = stderr;

    char const* loglevel_str[] = {
        "Error",
        "Warning",
        "Notice",
        "Info",
        "Debug"
    };
    time_t tim;
    time(&tim);
    char* time_str = ctime(&tim);
    if (time_str)
        time_str[strlen(time_str) - 1] = 0;
    fprintf(log_file, "%s [%s]: ", time_str, loglevel_str[val]);
    va_list ap;
    va_start(ap, fmt);
    vfprintf(log_file, fmt, ap);
    va_end(ap);
}
