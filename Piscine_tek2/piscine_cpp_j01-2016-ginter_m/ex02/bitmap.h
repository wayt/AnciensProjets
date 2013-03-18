/*
** bitmap.h for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_j01-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 09 14:05:29 2013 maxime ginters
** Last update Wed Jan 09 14:52:21 2013 maxime ginters
*/

#ifndef BITMAP_H_
# define BITMAP_H_

#include <stdint.h>
#include <sys/types.h>

typedef struct __attribute__((packed)) s_bmp_header
{
    uint16_t magic;
    uint32_t size;
    uint16_t _app1;
    uint16_t _app2;
    uint32_t offset;
} t_bmp_header;

typedef struct __attribute__((packed)) s_bmp_info_header
{
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bpp;
    uint32_t compression;
    uint32_t row_data_size;
    int32_t h_resolution;
    int32_t v_resolution;
    uint32_t palette_size;
    uint32_t important_colors;
} t_bmp_info_header;

void make_bmp_header(t_bmp_header* header, size_t size);
void make_bmp_info_header(t_bmp_info_header* header, size_t size);

#endif /* !BITMAP_H_ */
