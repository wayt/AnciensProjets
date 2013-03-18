/*
** aff_mem.c for core in /home/leroy_v/github/CoreWar/core
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Dec 15 15:22:22 2012 vincent leroy
** Last update Sun Dec 16 19:10:26 2012 vincent leroy
*/

#include "virtual_machine.h"

void	err_SDL()
{
  my_printf("%s\n", SDL_GetError());
  exit(1);
}

void	err_TTF()
{
  my_printf("%s\n", TTF_GetError());
  exit(1);
}

Uint32	change_color(SDL_Surface *square, int owner, unsigned char mem)
{
  if (owner == 1)
    return (SDL_MapRGB(square->format, 255, 0, 0));
  else if (owner == 2)
    return (SDL_MapRGB(square->format, 0, 255, 0));
  else if (owner == 3)
    return (SDL_MapRGB(square->format, 0, 0, 255));
  else if (owner == 4)
    return (SDL_MapRGB(square->format, 254, 216, 93));
  else
  {
    if (mem == 0)
      return (SDL_MapRGB(square->format, 0, 0, 0));
    else
      return (SDL_MapRGB(square->format, 255, 255, 255));
  }
}

int	get_joueur(int pid, t_vm *vm)
{
  int	i;
  t_program	*prog;

  i = 0;
  while (i < vm->prog_list->nb_elm)
  {
    prog = get_data(vm->prog_list, i);
    if (prog->active == 1 && prog->pid == pid)
    {
      i = prog->registre[0][REG_SIZE - 1];
      if (is_valid_player(vm, i) == 0)
        return (0);
      return (i);
    }
    ++i;
  }
  return (0);
}

int	get_joueur_pc(int pid, t_vm *vm)
{
  int	i;
  t_program	*prog;

  i = 0;
  while (i < vm->prog_list->nb_elm)
  {
    prog = get_data(vm->prog_list, i);
    if (prog->pid == pid)
      return (prog->pc);
    ++i;
  }
  return (0);
}

void	set_pixel(SDL_Surface *src, int x, int y, Uint32 pixel)
{
  int	bpp;
  Uint8 *p;

  if (x < 0 || x > src->w || y < 0 || y > src->h)
    return ;
  bpp = src->format->BytesPerPixel;
  p = (Uint8*)src->pixels + y * src->pitch + x * bpp;
  if (bpp == 1)
    *p = pixel;
  else if (bpp == 2)
    *(Uint16*)p = pixel;
  else if (bpp == 4)
    *(Uint32*)p = pixel;
}

void		trace_damier(int x, int y, Uint32 color, SDL_Surface *square)
{
  int	i;
  int	j;

  i = 0;
  while (i < WIDTH)
  {
    j = 0;
    while (j < WIDTH)
    {
      if (i % 2 == 0 && j % 2 == 1)
        set_pixel(square, i, j, color);
      else
        set_pixel(square, i, j, SDL_MapRGB(square->format, 0, 0, 0));
      j++;
    }
    i++;
  }
}

int	blit_text(char *txt, t_vm *vm, int y, int *x)
{
  SDL_Color	color;
  SDL_Rect	pos;
  SDL_Surface	*texte;
  int		h;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  if ((texte = TTF_RenderText_Solid(vm->police, txt, color)) == NULL)
    err_TTF();
  pos.y = y;
  pos.x = vm->screen->w - DECAL + 10;
  SDL_BlitSurface(texte, NULL, vm->screen, &pos);
  h = texte->h;
  if (x != NULL)
    *x = texte->w;
  SDL_FreeSurface(texte);
  return (h);
}

int	nb_prog_active(t_vm *vm)
{
  int	i;
  int	j;
  t_program	*prog;

  i = 0;
  j = 0;
  while (i < vm->prog_list->nb_elm)
  {
    prog = get_data(vm->prog_list, i);
    j += prog->active;
    i++;
  }
  return (j);
}

void	aff_info(t_vm *vm)
{
  char	buff[4096];
  int	y;
  int	i;
  int	x;
  int	tmp;
  SDL_Surface	*src;
  SDL_Rect	pos;

  y = 10;
  sprintf(buff, "nombre de cycles : %d", vm->cycle);
  y += blit_text(buff, vm, y, NULL) + 10;
  sprintf(buff, "nombre de \"cycles to die\" : %d", vm->cycle_to_die);
  y += blit_text(buff, vm, y, NULL) + 10;
  sprintf(buff, "nombre de processus : %d", vm->prog_list->nb_elm);
  y += blit_text(buff, vm, y, NULL) + 10;
  sprintf(buff, "nombre de processus en vie : %d", nb_prog_active(vm));
  y += blit_text(buff, vm, y, NULL) + 50;
  i = 1;
  if ((src = SDL_CreateRGBSurface(SDL_HWSURFACE, 30, 10, 32, 0, 0, 0, 0)) == NULL)
    err_SDL();
  while (i <= MAX_PLAYER)
  {
    if (vm->register_player[i] == 1)
    {
      sprintf(buff, "%s : ", get_prog_name(vm, i));
      tmp = blit_text(buff, vm, y, &x) + 10;
      SDL_FillRect(src, NULL, change_color(src, i, 0));
      pos.y = y;
      pos.x = vm->screen->w - DECAL + 20 + x;
      SDL_BlitSurface(src, NULL, vm->screen, &pos);
      y += tmp;
    }
    i++;
  }
  SDL_FreeSurface(src);
}

void	aff_barre(t_vm *vm)
{
  SDL_Surface	*barre;
  SDL_Rect	pos;

  if ((barre = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, vm->screen->h, 32, 0, 0, 0, 0)) == NULL)
    err_SDL();
  SDL_FillRect(barre, NULL, SDL_MapRGB(barre->format, 255, 255, 255));
  pos.x = vm->screen->w - DECAL;
  pos.y = 0;
  SDL_BlitSurface(barre, NULL, vm->screen, &pos);
  SDL_FreeSurface(barre);
}

void		aff_mem(t_vm *vm)
{
  int		i;
  int		j;
  SDL_Surface	*square;
  SDL_Rect	pos;
  t_program	*prog;

  SDL_FillRect(vm->screen, NULL, SDL_MapRGB(vm->screen->format, 0, 0, 0));
  square = SDL_CreateRGBSurface(SDL_HWSURFACE, WIDTH, WIDTH, 32, 0, 0, 0, 0);
  if (square == NULL)
    err_SDL();
  i = 0;
  while (i < MEM_SIZE)
  {
    j = get_joueur(vm->mem_owner[i], vm);
    {
      pos.x = i / NB_COL * WIDTH;
      pos.y = i % NB_COL * WIDTH;
      SDL_FillRect(square, NULL, change_color(square, j, vm->memory[i]));
    }
    SDL_BlitSurface(square, NULL, vm->screen, &pos);
    i++;
  }
  i = 0;
  while (i < vm->prog_list->nb_elm)
  {
    prog = get_data(vm->prog_list, i);
    if (prog->active == 1)
    {
      trace_damier(prog->pc / NB_COL * WIDTH, prog->pc % NB_COL * WIDTH, change_color(square, get_prog_number(prog, vm), 0), square);
      pos.x = prog->pc / NB_COL * WIDTH;
      pos.y = prog->pc % NB_COL * WIDTH;
      SDL_BlitSurface(square, NULL, vm->screen, &pos);
    }
    i++;
  }
  aff_barre(vm);
  aff_info(vm);
  SDL_Flip(vm->screen);
  SDL_FreeSurface(square);
}
