/*
** op.c for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Sun Dec 16 18:08:20 2012 vincent leroy
*/

/*
** Ne pas passer ce fichier dans la moulinette de Norme.
*/

#include "op.h"

op_t    op_tab[] =
{
  {"live",  0,  1, {T_DIR},                                               {T_VAL},                1,  10,   "alive"},
  {"ld",    1,  2, {T_DIR | T_IND | T_REG, T_REG},                        {T_VAL, T_VAL},         2,  5,    "load"},
  {"st",    1,  2, {T_REG, T_IND | T_REG},                                {T_VAL, T_VAL},         3,  5,    "store"},
  {"add",   1,  3, {T_REG, T_REG, T_REG},                                 {T_VAL, T_VAL, T_VAL},  4,  10,   "addition"},
  {"sub",   1,  3, {T_REG, T_REG, T_REG},                                 {T_VAL, T_VAL, T_VAL},  5,  10,   "soustraction"},
  {"and",   1,  3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, {T_VAL, T_VAL, T_VAL},  6,  6,    "et (and  r1, r2, r3   r1&r2 -> r3"},
  {"or",    1,  3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, {T_VAL, T_VAL, T_VAL},  7,  6,    "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
  {"xor",   1,  3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, {T_VAL, T_VAL, T_VAL},  8,  6,    "ou (xor  r1, r2, r3   r1^r2 -> r3"},
  {"zjmp",  0,  1, {T_DIR},                                               {T_IDX},                9,  20,   "jump if zero"},
  {"ldi",   1,  3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},         {T_IDX, T_IDX, T_VAL},  10, 25,   "load index"},
  {"sti",   1,  3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},         {T_VAL, T_IDX, T_IDX},  11, 25,   "store index"},
  {"fork",  0,  1, {T_DIR},                                               {T_IDX},                12, 800,  "fork"},
  {"lld",   1,  2, {T_DIR | T_IND, T_REG},                                {T_VAL, T_VAL},         13, 10,   "long load"},
  {"lldi",  1,  3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},         {T_VAL, T_VAL},         14, 50,   "long load index"},
  {"lfork", 0,  1, {T_DIR},                                               {T_IDX},                15, 1000, "long fork"},
  {"aff",   1,  1, {T_REG},                                               {T_VAL},                16, 2,    "aff"},
  {"mul",   1,  3, {T_REG, T_REG, T_REG},                                 {T_VAL, T_VAL, T_VAL},  17, 10,   "multiplication"},
  {"div",   1,  3, {T_REG, T_REG, T_REG},                                 {T_VAL, T_VAL, T_VAL},  18, 10,   "division"},
  {"mod",   1,  3, {T_REG, T_REG, T_REG},                                 {T_VAL, T_VAL, T_VAL},  19, 10,   "modulo"},
  {0,       0,  0, {0},                                                   {0},                    0,  0,    0}
};
