/*
** mul_div.c for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d02m-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 10 09:18:58 2013 maxime ginters
** Last update Thu Jan 10 09:31:26 2013 maxime ginters
*/

void add_mul_4param(int first, int second, int *add, int *mul)
{
    if (add)
        *add = first + second;
    if (mul)
        *mul = first * second;
}

void add_mul_2param(int* first, int* second)
{
    if (!first || !second)
        return;

    int one = *first;
    int two = *second;

    *first = one + two;
    *second = one * two;
}
