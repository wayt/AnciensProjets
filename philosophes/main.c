/*
 ** main.c for philosophes in /Storage/Epitech/philosophes
 **
 ** Made by maxime ginters
 ** Login  <ginter_m@epitech.eu>
 **
 ** Started on  Mon Mar 18 15:34:38 2013 maxime ginters
 ** Last update Sun Mar 24 13:51:01 2013 maxime ginters
 */

#include "philosophes.h"

pthread_mutex_t	stick_mutex[STICK_COUNT];

void		start_threads(t_philosophe ph[PHILO_COUNT])
{
  int		i;

  i = 0;
  while (i < PHILO_COUNT)
  {
    pthread_create(&ph[i].thread, NULL, philosophe_worker, &ph[i]);
    ++i;
  }
}

void		join_threads(t_philosophe ph[PHILO_COUNT])
{
  int		i;

  i = 0;
  while (i < PHILO_COUNT)
  {
    pthread_join(ph[i].thread, NULL);
    ++i;
  }
}

int		main()
{
  t_philosophe	philo[PHILO_COUNT];

  init_sticks();
  init_philosophes(philo);
  start_threads(philo);
  join_threads(philo);
  return (0);
}
