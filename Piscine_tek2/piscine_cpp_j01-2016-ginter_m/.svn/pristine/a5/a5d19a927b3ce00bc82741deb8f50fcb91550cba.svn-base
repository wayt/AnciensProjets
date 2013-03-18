/*
** main.c for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_j01-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 09 17:18:35 2013 maxime ginters
** Last update Wed Jan 09 18:47:46 2013 maxime ginters
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "drawing.h"
#include "bitmap.h"

void menger(size_t, uint32_t, t_point*, uint32_t**);

int main(int ac, char** av)
{
    if (ac < 4)
    {
        fprintf(stderr, "menger_face file_name size level\n");
        return 1;
    }

    char* name = av[1];
    size_t size = atoi(av[2]);
    uint32_t level = atoi(av[3]);

    t_bmp_header header;
    t_bmp_info_header info;
    uint32_t* buffer;
    uint32_t** img;
    t_point p = {0, 0};
    int d;

    buffer = calloc(size * size, sizeof(*buffer));
    img = malloc(size * sizeof(*img));
    for (size_t i = 0; i < size; ++i)
        img[i] = buffer + i * size;

    make_bmp_header(&header, size);
    make_bmp_info_header(&info, size);

    draw_square(img, &p, size, 0x00000000);

    menger(size, level, &p, img);

    d = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    write(d, &header, sizeof(header));
    write(d, &info, sizeof(info));
    write(d, buffer, size * size * sizeof(*buffer));
    close(d);
    return 0;
}
