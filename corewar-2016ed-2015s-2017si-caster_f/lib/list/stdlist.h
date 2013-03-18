/*
** stdlist.h for dll in /home/leroy_v/Epitech/linked_list/dll
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Nov 17 10:06:41 2012 vincent leroy
** Last update Tue Dec 04 20:06:39 2012 vincent leroy
*/

#ifndef STDLIST_H_
# define STDLIST_H_

#include <stdlib.h>

/*
** lib de liste circulaire doublement chainee
*/

typedef struct s_elm
{
  void		*data;
  struct s_elm	*next;
  struct s_elm	*prev;
}		t_elm;

/*
** Les positions des elements vont de 0 a nb_elm - 1
*/

typedef struct s_list
{
  void	*data;
  int	nb_elm;
  t_elm	*first;
  t_elm	*last;
}	t_list;

/*
** retour des fonctions :
**
** les fonctions renvoient 0 si tout est OK
** sinon elles renvoient :
**  1 si un des parametres envoyer est incorrect
**  2 si un malloc a fail
**  3 si l'elm demande est NULL (n'est pas cense arriver)
**
** Pour les fonctions qui renvoient un pointeur :
** elles renvoient NULL si il y a un probleme
*/

t_list	*create_list(void *data);
t_elm	*get_elm(t_list *list, int pos);
void	*get_data(t_list *list, int pos);
int	search_elm(t_list *list, t_elm *to_find);
int	search_data(t_list *list, void *data_ref, int (*cmp)());
int	replace_elm(t_list *list, void *data, int pos, void (*freedata)());
int	add_last_elm(t_list *list, void *data);
int	add_first_elm(t_list *list, void *data);
int	insert_elm(t_list *list, void *data, int pos);
int	del_first_elm(t_list *list, void (*freedata)());
int	del_last_elm(t_list *list, void (*freedata)());
int	del_elm(t_list *list, int pos, void (*freedata)());
int	del_all_list(t_list **list, void (*freeelm)(), void (*freelist)());
int	sort_list(t_list *list, int abc, int (*cmp)());

#endif /* !STDLIST_H_ */
