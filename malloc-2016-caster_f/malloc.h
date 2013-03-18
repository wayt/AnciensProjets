/*
** malloc.h for Malloc in /Storage/Epitech/Malloc
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Feb 07 16:30:10 2013 maxime ginters
** Last update Sat Feb 09 17:02:37 2013 fabien casters
*/

#ifndef MALLOC_H_
# define MALLOC_H_

#include <unistd.h>
#include <pthread.h>
#include <string.h>

typedef struct s_malloc
{
  size_t	size;
  void		*next;
  char		used;
} malloc_t;

malloc_t		*mlc;
extern pthread_mutex_t	__access;

#define LOCK pthread_mutex_lock(&__access)
#define UNLOCK pthread_mutex_unlock(&__access)

#define T_SIZE sizeof(malloc_t)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void	free(void *);
void	*realloc(void *, size_t);
void	*malloc(size_t);
void	*found_mlc_with_size(size_t);
size_t	get_size_to_alloc(size_t);
void	append_mlc(malloc_t *);
void	remove_from_mlc(malloc_t *);
int	_safe_free(malloc_t *);
void	free(void *);

#endif /* !MALLOC_H_ */
