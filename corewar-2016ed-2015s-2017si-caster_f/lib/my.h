/*
** my.h for lib in /home/leroy_v/Epitech/corewar/lib
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Mon Dec 03 14:21:13 2012 vincent leroy
** Last update Tue Dec 11 17:10:33 2012 vincent leroy
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>

void	my_printf(char *format, ...);
int	my_getnbr(char *str);
void	*my_malloc(int len, char *msg);
void	my_memset(void *buf, char c, int size);
int	my_putnbr(int n);
int	my_putstr(char *str);
char	**my_str_to_wordtab(char *str, char *sepa);
int	my_strcmp(char *s1, char *s2);
int	my_strlen(char *str);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strcat(char *dest, char *src);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *str);
int	my_strncmp(char *s1, char *s2, int n);
void	free_tab(char **tab);
int	is_bigendian();
void	*my_memcpy(void *dest, void *src, int n);

#endif /* !MY_H_ */
