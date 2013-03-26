/*
 ** philosophes.h for philosophes in /Storage/Epitech/philosophes
 **
 ** Made by maxime ginters
 ** Login  <ginter_m@epitech.eu>
 **
 ** Started on  Mon Mar 18 15:40:38 2013 maxime ginters
 ** Last update Sun Mar 24 15:00:48 2013 fabien casters
 */

#ifndef PHILOSOPHES_H_
# define PHILOSOPHES_H_

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define STICK_COUNT 7
#define PHILO_COUNT STICK_COUNT

#define THINK_TIME 2
#define EAT_TIME 3

#define LOCK(a) (pthread_mutex_lock(a))
#define TRYLOCK(a) (pthread_mutex_trylock(a))
#define UNLOCK(a) (pthread_mutex_unlock(a))

#define LEFT_THINKING(p) (p->left_philo->state == STATE_THINK ? 1 : 0)
#define RIGHT_THINKING(p) (p->right_philo->state == STATE_THINK ? 1 : 0)

extern pthread_mutex_t	stick_mutex[STICK_COUNT];

typedef enum
{
  STATE_NONE		= 0,
  STATE_EAT		= 1,
  STATE_SLEEP		= 2,
  STATE_THINK		= 3
}			e_states;

typedef struct s_philosophe
{
  int			id;
  e_states		state;
  pthread_mutex_t	*left_stick;
  struct s_philosophe	*left_philo;
  pthread_mutex_t	*right_stick;
  struct s_philosophe	*right_philo;
  pthread_t		thread;

}			t_philosophe;

void	init_sticks();
void	init_philosophes(t_philosophe philo[PHILO_COUNT]);
void	*philosophe_worker(void *philo);
void	philosophe_sleep(t_philosophe *philo);
void	philosophe_think(t_philosophe *philo);
void	philosophe_eat(t_philosophe *philo);

#endif /* !PHILOSOPHES_H_ */
