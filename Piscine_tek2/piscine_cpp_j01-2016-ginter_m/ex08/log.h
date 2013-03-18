/*
** log.h for ex08 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_j01-2016-ginter_m/ex08
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 09 22:25:57 2013 maxime ginters
** Last update Wed Jan 09 23:03:59 2013 maxime ginters
*/

#ifndef LOG_H_
# define LOG_H_

#include <stdio.h>

enum LogLevel
{
    Error       = 0,
    Warning     = 1,
    Notice      = 2,
    Info        = 3,
    Debug       = 4
};


enum LogLevel get_log_level();
enum LogLevel set_log_level(enum LogLevel val);
int set_log_file(char const* file);
int close_log_file();
int log_to_stdout();
int log_to_stderr();
void log_msg(enum LogLevel val, char const* fmt, ...);

#endif /* !LOG_H_ */
