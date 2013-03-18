/*
** main.c for colle2 in /home/ginter_m/colle2
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Oct 13 12:13:32 2012 maxime ginters
** Last update Sun Oct 14 17:15:48 2012 maxime ginters
*/

/*
** Re déclaration des fonctions implémenté dans un autre fichier
** pour éviter les conflits de type (similaire a un .h)
*/

void	my_putstr(char *);
int	my_strcmp(char *, char *);
int	init_params(int , char **, int *, int *);
int	my_strlen(char *);
int	my_getnbr(char *);
void	colle2_4(char *, int, int);

int	main(int argc, char **argv)
{
  int	size; /* variable pour la taille max de la chaine */
  int	speed; /* vitesse qui sera passé au usleep() */
  int	pos; /* position dans le tableau argv de la chaine à annimer */

  if (argc < 2) /* si aucun argument */
  {
    my_putstr("usage : ./colle2-4 <chaine> -speed <speed> -size <size>\n");
    return (1);
  }
  size = 10; /* valeurs par défaut */
  speed = 1000;
  pos = init_params(argc, argv, &size, &speed); /* Initialisation des parametres */
  /*
   * Je passe en parametre &size et &speed, c'est à dire l'adresse de ces variables,
   * ainsi quand je les modifie dans la fonction init_params(), elles sont modifier dans le main
   */
  if (pos == 0) /* si la position de la chaine à annimé est 0 (le nom du prog) je considère ça comme une erreur */
  {
    my_putstr("usage : ./colle2-4 <chaine> -speed <speed> -size <size>\n");
    return (1);
  }
  colle2_4(argv[pos], size, speed); /* fonction qui fait tout, présente dans le fichier colle2_4.c */
  return (0);
}
/*
** Initialisation des parametres
** comme dit plus haut, size et speed sont des pointeurs, leurs contenu sera modifié dans la variable d'origine
** la valeur retourné est la position de la chaine à annimer dans le tableau argv
** retourne 0 en cas d'erreur
*/
int	init_params(int argc, char **argv, int *size, int *speed)
{
  int	i;
  int	pos;

  i = 1; /* je commence a 1 car argv[0] est le nom du programme (osef) */
  pos = 0;
  while (i < argc)
  {
    if (my_strcmp(argv[i], "-size") == 0) /* si c'est le paramettre -size */
    {
      /* alors le prochain paramettre est la taille
      ** si on lance le programme ainsi : ./a.out -size
      ** argv[i + 1] pointera dans le neant, et donc Erreur de segementation
      ** j'utilise donc un ternaire pour vérifier cela
      */
      *size = (i + 1 < argc ? my_getnbr(argv[i + 1]) : 0); /* == if (i + 1 < argc) { *size = my_getnbr(argv[i + 1]); } else { *size = 0; } */
      if (*size <= 0) /* erreur */
        return (0);
      ++i; /* on doit incrémenté de deux car -size + valeur prend 2 case, la deuxième incrémentation est faite plus bas. */
    }
    else if (my_strcmp(argv[i], "-speed") == 0) /* pareil que pour -size */
    {
      *speed = (i + 1 < argc ? my_getnbr(argv[i + 1]) : 0);
      if (*speed <= 0)
        return (0);
      ++i;
    }
    else if (pos == 0) /* pos ne prendra la valeur de i que 1 seul fois dans tout le while, ainsi, la premiere chaine valide comme chaine d'annimation est prise en compte */
      pos = i;
    ++i;
  }
  return (pos);
}
