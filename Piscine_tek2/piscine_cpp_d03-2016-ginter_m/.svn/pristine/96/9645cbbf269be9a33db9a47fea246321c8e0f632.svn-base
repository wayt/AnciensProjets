/*
** String.h for ex00 in /home/fest/Epitech/Piscine_tek2/Jour03/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 11 09:09:19 2013 maxime ginters
** Last update Fri Jan 11 13:46:25 2013 maxime ginters
*/

#ifndef STRING_H_
# define STRING_H_

#include <stdlib.h>

typedef struct s_string String;

struct s_string
{
    char* str;
    void (*assign_s)(String* this, String const* str);
    void (*assign_c)(String* this, char const* s);
    void (*append_s)(String* this, String const* ap);
    void (*append_c)(String* this, char const* ap);
    char (*at)(String* this, size_t pos);
    void (*clear)(String* this);
    int (*size)(String* this);
    int (*compare_s)(String* this, const String* str);
    int (*compare_c)(String* this, char const* str);
    size_t (*copy)(String* this, char* s, size_t n, size_t pos);
    char const* (*c_str)(String* this);
    int (*empty)(String* this);
    int (*find_s)(String* this, const String* str, size_t pos);
    int (*find_c)(String* this, char const* str, size_t pos);
    void (*insert_s)(String* this, size_t pos, String const* str);
    void (*insert_c)(String* this, size_t pos, char const* str);
    int (*to_int)(String* this);
    String* (*split_s)(String* this, char separator);
    char** (*split_c)(String* this, char separator);
    void (*aff)(String* this);
    void (*join_c)(String* this, char delim, char const** tab);
    void (*join_s)(String* this, char delim, String* tab);
    String* (*substr)(String* this, int offset, int length);
};

void StringInit(String* this, char const* s);
void StringDestroy(String* this);
void assign_s(String* this, String const* str);
void assign_c(String* this, char const* s);
void append_s(String* this, String const* ap);
void append_c(String* this, char const* ap);
char at(String* this, size_t pos);
void clear(String* this);
int size(String* this);
int compare_s(String* this, const String* str);
int compare_c(String* this, char const* str);
size_t copy(String* this, char* s, size_t n, size_t pos);
char const* c_str(String* this);
int empty(String* this);
int find_s(String* this, const String* str, size_t pos);
int find_c(String* this, char const* str, size_t pos);
void insert_c(String* this, size_t pos, char const* str);
void insert_s(String* this, size_t pos, String const* str);
int to_int(String* this);
String* split_s(String* this, char separator);
char** split_c(String* this, char separator);
void aff(String* this);
void join_s(String* this, char delim, String* tab);
void join_c(String* this, char delim, char const** tab);
String* substr(String* this, int offset, int length);

#endif /* !STRING_H_ */
