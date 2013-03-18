/*
** colle2_4_prog.c for colle2_2_prog in /home/jean-b_x//colles_piscine/colle2_4/colle2-4
** 
** Made by xavier jean-bart
** Login   <jean-b_x@epitech.net>
** 
** Started on  Sat Oct 13 13:44:31 2012 xavier jean-bart
** Last update Sun Oct 14 17:28:10 2012 maxime ginters
*/

int	my_strlen(char *);
int	is_alphanum(char);
int	is_punctuation(char);

/*
** Calcule la taille finale de la chaine *str en insérant i espace(s)
** et renvoie ce résultat
*/
int	calc_space(char *str, int i)
{
  int	j;
  int	size;

  j = 0;
  size = my_strlen(str);
  while (size > 0 && str[j + 1] != '\0')
    {
      if (is_alphanum(str[j]) == 1 && is_alphanum(str[j + 1]) == 1)
	size += i;
      /* Je check ici si le caractère actuel est une ponctuation et que le prochain aussi
      ** et j'inverse cette condition, ex ! if (!(1 == 1))
      ** ce qui donne donc : "Si les deux caractères ne sont pas des ponctuations"
      */
      else if (!(is_punctuation(str[j]) == 1 && is_punctuation(str[j + 1]) == 1))
	size += i;
      j++;
    }
  return (size);
}

/*
** Petit utilitaire qui fait le café
*/
void	move_curs(int size, int speed)
{
  my_putchar('\r'); /* ramène le cuseur au début */
  usleep(speed); /* attend "speed" milisecondes */
  my_putchar('\r'); /* ramène le curseur au début */
  aff_space(size + 1); /* insére "size + 1" espace (nettoye l'affichage) */
  my_putchar('\r'); /* etc */
}

/*
** Autre utilitaire qui fait le café
** en gros, ça affiche le char courant, les espaces associé et incrémente le compteur
** pour du gain de ligne dans la fonction colle2_4()
*/
void	aff_char(char *str, int *j, int i)
{
  write(1, &str[*j], 1);
  if (is_alphanum(str[*j]) == 1 && is_alphanum(str[*j + 1]) == 1)
    aff_space(i);
  else if (!(is_punctuation(str[*j]) == 1 && is_punctuation(str[*j + 1])))
    aff_space(i);
  (*j)++; /* si je fais *j++, je prend le contenu de j et ensuite j'incrémente son adresse */
  /* Ici, via les () j'incrémente son contenu (astuce très importante) */
}

/*
** La fonction principale, qui utilise tout ce qu'il y avant
*/
void	colle2_4(char *str, int size, int speed)
{
  int	i;
  int	j;

  i = 0;
  while (1) /* Oui oui, c'est une boucle infinie */
    {
      while (calc_space(str, i) <= size) /* tant qu'on est inférieur à la taille max de la chaine */
	{
	  j = 0;
	  while (str[j] != '\0') /* Je parcours chaque lettre de ma chaine a annimer */
	    aff_char(str, &j, i); /* fonction qui s'occupe de l'affichage du char, des espaces et de l'incrémentation de j */
	  move_curs(size, speed);/* gere la position du curseur, l'attente et le nettoyage de l'affichage */
	  i++;
	}
      i--; /* Lorsqu'on sort du while au dessus, i à une valeur qui fait que la chaine serait trop grande a afficher*/
      /* Il faut donc le réduire de 1 pour que la chaine ne soit pas affiché en dessous, tu peux essayer sans pour voir */
      while (i > 0) /* tant que je suis pas revenu à 0 espaces */
	{
	  j = 0;
	  while (str[j] != '\0') /* comme au dessus ;) */
	    aff_char(str, &j, i);
	  move_curs(size, speed);
          i--;
	}
    }
} /* done */
