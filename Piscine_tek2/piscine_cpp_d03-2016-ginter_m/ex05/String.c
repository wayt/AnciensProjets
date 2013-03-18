/*
** String.c for ex00 in /home/fest/Epitech/Piscine_tek2/Jour03/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 11 09:10:43 2013 maxime ginters
** Last update Sat Jan 12 00:02:33 2013 maxime ginters
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "String.h"

void StringInit(String* this, char const* s)
{
    if (!this)
        return;
    this->str = NULL;
    if (s)
        this->str   = strdup(s);
    this->assign_s  = &assign_s;
    this->assign_c  = &assign_c;
    this->append_s  = &append_s;
    this->append_c  = &append_c;
    this->at        = &at;
    this->clear     = &clear;
    this->size      = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy      = &copy;
    this->c_str     = &c_str;
    this->empty     = &empty;
    this->find_s    = &find_s;
    this->find_c    = &find_c;
    this->insert_s  = &insert_s;
    this->insert_c  = &insert_c;
    this->to_int    = &to_int;
    this->split_s   = &split_s;
    this->split_c   = &split_c;
    this->aff       = &aff;
    this->join_s    = &join_s;
    this->join_c    = &join_c;
    this->substr    = &substr;
}

void StringDestroy(String* this)
{
    if (this && this->str)
    {
        free(this->str);
        this->str = NULL;
    }
}

void assign_s(String* this, String const* str)
{
    if (this && str)
        assign_c(this, str->str);
}

void assign_c(String* this, const char* s)
{
    if (!this || !s)
        return;
    if (this->str)
        free(this->str);
    this->str = strdup(s);
}

void append_s(String* this, String const* ap)
{
    if (this && ap)
        append_c(this, ap->str);
}

void append_c(String* this, char const* ap)
{
    if (!this || !ap)
        return;
    size_t len = (this->str ? strlen(this->str) : 0);
    size_t lenap = strlen(ap);
    this->str = realloc(this->str, len + lenap + 1);
    memset(this->str + len, 0, lenap + 1);
    if (!this->str)
        return;
    this->str = strcat(this->str, ap);
}

char at(String* this, size_t pos)
{
    if (!this)
        return -1;
    if (!this->str)
        return -1;
    if (pos > strlen(this->str) - 1)
        return -1;
    return this->str[pos];
}

void clear(String* this)
{
    if (!this || !this->str)
        return;

    memset(this->str, 0, strlen(this->str));
}

int size(String* this)
{
    if (!this || !this->str)
        return -1;
    return strlen(this->str);
}

int compare_s(String* this, const String* str)
{

    if (!this && !str)
        return 0;
    return compare_c(this, str ? str->str : NULL);
}

int compare_c(String* this, char const* str)
{
    if (!this)
        return -1;
    if (this->str && !str)
        return 1;
    if (!this->str && str)
        return -1;
    if (!this->str && !str)
        return 0;
    return strcmp(this->str, str);
}

size_t copy(String* this, char* s, size_t n, size_t pos)
{
    if (!this || !s || !this->str)
        return 0;
    size_t i;
    size_t len = strlen(this->str);
    for (i = 0; i + pos < len && i < n; ++i)
        s[i] = this->str[i + pos];
    if (strlen(s) < n)
        s[i++] = 0;
    return i;
}

char const* c_str(String* this)
{
    if (!this)
        return NULL;
    return this->str;
}

int empty(String* this)
{
    if (!this || !this->str)
        return 1;
    return (strlen(this->str) == 0 ? 1 : -1);
}

int find_s(String* this, const String* str, size_t pos)
{
    if (!this || !str || !this->str || !str->str)
        return -1;
    return find_c(this, str->str, pos);
}

int find_c(String* this, char const* str, size_t pos)
{
    if (!this || !this->str || !str)
        return -1;
    if (pos > strlen(this->str) - 1)
        return -1;

    char* str_pos = strstr(this->str + pos, str);
    if (!str_pos)
        return -1;
    return str_pos - this->str;
}

void insert_s(String* this, size_t pos, String const* str)
{
    if (!this || !str || !str->str)
        return;
    insert_c(this, pos, str->str);
}

void insert_c(String* this, size_t pos, char const* str)
{
    if (!this || !str)
        return;
    size_t t_str_size = this->str ? strlen(this->str) : 0;
    size_t str_size = strlen(str);
    char* tmp = calloc(t_str_size + str_size + 1, sizeof(char));
    if (pos > t_str_size)
        pos = t_str_size;
    strncpy(tmp, this->str, pos);
    strcat(tmp, str);
    if (pos < t_str_size)
        strcat(tmp, this->str + pos);
    free(this->str);
    this->str = tmp;
}

int to_int(String* this)
{
    if (!this || !this->str)
        return 0;
    return atoi(this->str);
}

String* split_s(String* this, char separator)
{
    if (!this || !this->str)
        return NULL;
    char** tab = split_c(this, separator);
    size_t i = 0;
    String* strs = NULL;
    for (i = 0; tab && tab[i]; ++i)
    {
        strs = realloc(strs, (i + 1) * sizeof(String));
        StringInit(&strs[i], tab[i]);
    }
    strs = realloc(strs, (i + 1) * sizeof(String));
    StringInit(&strs[i], 0x0);
    return strs;
}

char* my_strtok(char* str, char sep)
{
    static char* _str;

    if (str)
        _str = str;
    if (!str && !_str)
        return NULL;
    static char tmp[200];
    memset(tmp, 0, 200);
    int i = 0;
    while (*_str && *_str != sep)
    {
        tmp[i++] = *_str;
        ++_str;
    }
    if (i == 0 && *_str == 0)
        return NULL;
    if (*_str == sep)
        ++_str;
    return (tmp);
}

char** split_c(String* this, char separator)
{
    if (!this || !this->str)
        return NULL;

    char** tab = NULL;
    char* split = my_strtok(this->str, separator);
    if (!split)
    {
        tab = malloc(2 * sizeof(char*));
        tab[0] = strdup(this->str);
        tab[1] = NULL;
        return tab;
    }
    size_t size = 0;
    do
    {
        tab = realloc(tab, (1 + size) * sizeof(char*));
        tab[size++] = strdup(split);
    } while ((split = my_strtok(NULL, separator)));
    tab = realloc(tab, (1 + size) * sizeof(char*));
    tab[size] = NULL;
    return tab;
}

void aff(String* this)
{
    if (!this || !this->str)
        return;
    fflush(stdout);
    write(1, this->str, strlen(this->str));
}

void join_s(String* this, char delim, String* tab)
{
    if (!this || !tab)
        return;
    if (this->str)
    {
        free(this->str);
        this->str = NULL;
    }
    size_t i;
    char actere[2] = {0, 0};
    actere[0] = delim;
    for (i = 0; (&tab[i])->str; ++i)
    {
        if (i != 0)
            append_c(this, actere);
        append_s(this, &tab[i]);
    }
}

void join_c(String* this, char delim, char const** tab)
{
    if (!this || !tab)
        return;
    if (this->str)
    {
        free(this->str);
        this->str = NULL;
    }
    size_t i;
    char actere[2] = {0, 0};
    actere[0] = delim;
    for (i = 0; tab[i]; ++i)
    {
        if (i != 0)
            append_c(this, actere);
        append_c(this, tab[i]);
    }
}

String* substr(String* this, int offset, int length)
{
    if (!this || !this->str)
        return NULL;

    char* back = NULL;
    int str_len = strlen(this->str);
    offset += (offset < 0 ? strlen(this->str) : 0);
    back = calloc(((length < 0 ? -(length) : length)  + 1), sizeof(char));
    int i;
    for (i = 0; i + offset < str_len && i < length; ++i)
        back[i] = this->str[(length > 0 ? i : -i) + offset];
    String* back_string = malloc(sizeof(String));
    StringInit(back_string, back);
    free(back);
    return back_string;
}
