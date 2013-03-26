/*
 ** philosophes.c for philosophes in /Storage/Epitech/philosophes
 **
 ** Made by maxime ginters
 ** Login  <ginter_m@epitech.eu>
 **
 ** Started on  Sat Mar 23 22:44:49 2013 maxime ginters
 ** Last update Sun Mar 24 13:52:37 2013 maxime ginters
 */

#include "philosophes.h"

void		init_sticks()
{
  int		i;

  i = 0;
  while (i < STICK_COUNT)
  {
    pthread_mutex_init(&stick_mutex[i], NULL);
    ++i;
  }
}

void		init_philosophes(t_philosophe phil[PHILO_COUNT])
{
  int		i;

  i = 0;
  while (i < PHILO_COUNT)
  {
    phil[i].id = i + 1;
    phil[i].state = STATE_NONE;
    phil[i].left_stick = &stick_mutex[(i - 1 >= 0 ? i : STICK_COUNT) - 1];
    phil[i].left_philo = &phil[(i - 1 >= 0 ? i : PHILO_COUNT) - 1];
    phil[i].right_stick = &stick_mutex[i];
    phil[i].right_philo = &phil[i + 1 > PHILO_COUNT - 1 ? 0 : PHILO_COUNT + 1];
    ++i;
  }
}

void		*philosophe_worker(void *data)
{
  t_philosophe	*philo;

  philo = (t_philosophe*)data;
  while (1)
  {
    if (philo->state == STATE_SLEEP)
    {
      if (LEFT_THINKING(philo) == 0 && TRYLOCK(philo->left_stick) == 0)
        philosophe_think(philo);
      else if (RIGHT_THINKING(philo) == 0 && TRYLOCK(philo->right_stick) == 0)
        philosophe_think(philo);
      usleep(20000);
    }
    else if (philo->state == STATE_EAT || philo->state == STATE_NONE)
      philosophe_sleep(philo);
    else if (philo->state == STATE_THINK)
    {
      if (TRYLOCK(philo->left_stick) == 0 || TRYLOCK(philo->right_stick) == 0)
        philosophe_eat(philo);
      else
        usleep(20000);
    }
  }
  return (NULL);
}
