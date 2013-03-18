/*
** bitmap_header.c for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_j01-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 09 14:00:19 2013 maxime ginters
** Last update Wed Jan 09 16:15:50 2013 maxime ginters
*/

#include <string.h>
#include "bitmap.h"

int is_bigendian()
{
    int nb;
    char *c;

    nb = 0x70AB12CD;
    c = (char*)&nb;
    if (*c == 0x70)
        return (1);
    return (0);
}

void make_bmp_header(t_bmp_header* header, size_t size)
{
    memset(header, 0, sizeof(t_bmp_header));
    header->magic = is_bigendian() == 1 ? 0x424D : 0x4D42;
    header->size = size * size * sizeof(uint32_t) + sizeof(t_bmp_header) + sizeof(t_bmp_info_header);
    header->offset = sizeof(t_bmp_header) + sizeof(t_bmp_info_header);
}

void make_bmp_info_header(t_bmp_info_header* header, size_t size)
{
    memset(header, 0, sizeof(t_bmp_info_header));
    header->size = 40;
    header->width = size;
    header->height = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->row_data_size = size * size * sizeof(uint32_t);
    header->v_resolution = 0;
    header->h_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}
