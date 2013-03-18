/*
** ex_6.h for ex06 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_j01-2016-ginter_m/ex06
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 09 20:21:56 2013 maxime ginters
** Last update Wed Jan 09 21:01:11 2013 maxime ginters
*/

#ifndef EX_6_H_
# define EX_6_H_

#include <stdint.h>

typedef union
{
    struct
    {
        uint16_t  foo;
        union
        {
            uint16_t bar;
            uint16_t foo;
        } bar;
    } foo;
    uint32_t bar;

} t_foo;

#endif /* !EX_6_H_ */
