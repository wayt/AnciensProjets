/*
** behaviors.c for philosophes in /home/vaga/Projects/tek2/philosophe
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Sun Mar 24 14:55:26 2013 fabien casters
** Last update Sun Mar 24 15:10:30 2013 fabien casters
*/

#include "philosophes.h"

pthread_mutex_t	printf_mutex = PTHREAD_MUTEX_INITIALIZER;

void		philosophe_sleep(t_philosophe *philo)
{
  UNLOCK(philo->left_stick);
  UNLOCK(philo->right_stick);
  philo->state = STATE_SLEEP;
  LOCK(&printf_mutex);
  printf("Philosophe %d is sleeping\n", philo->id);
  UNLOCK(&printf_mutex);
  usleep(20000);
}

void		philosophe_think(t_philosophe *philo)
{
  philo->state = STATE_THINK;
  LOCK(&printf_mutex);
  printf("Philosophe %d is going to think for %d secondes\n",
         philo->id, THINK_TIME);
  UNLOCK(&printf_mutex);
  sleep(THINK_TIME);
}

void		philosophe_eat(t_philosophe *philo)
{
  philo->state = STATE_EAT;
  LOCK(&printf_mutex);
  printf("Philosophe %d start to eat for %d secondes\n", philo->id, EAT_TIME);
  UNLOCK(&printf_mutex);
  sleep(EAT_TIME);
}
