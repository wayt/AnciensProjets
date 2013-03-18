/*
** vm_launcher.c for virtual_machine in /home/fest/Epitech/CoreWar/core/virtual_machine
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Dec 05 17:35:59 2012 maxime ginters
** Last update Sun Dec 16 17:57:41 2012 vincent leroy
*/

#include <stdio.h>
#include <fcntl.h>
#include "virtual_machine.h"
#include "my.h"
#include "op.h"
#include "corewar.h"
#include "stdlist.h"

#define ABS(a) (((a) < 0) ? -(a) : (a))

int	mem_reader(t_vm *vm, int fd, t_program *prog)
{
  int	to_read;
  int	mem_offset;
  int	rd;

  mem_offset = prog->prog_param->load_address;
  to_read = prog->header->prog_size;
  owner_set(vm->mem_owner, prog->prog_param->prog_number, mem_offset, to_read);
  while (to_read > 0)
  {
    rd = to_read;
    if (mem_offset + to_read > MEM_SIZE)
      rd = MEM_SIZE - mem_offset;
    if ((rd = read(fd, vm->memory + mem_offset, rd)) == 0)
      return (1);
    to_read -= rd;
    if (to_read > 0)
      mem_offset = 0;
  }
  return (0);
}

t_program	*load_program(t_prog_param *prog, t_vm *vm)
{
  t_program	*program;
  int	fd;

  if ((fd = open(prog->prog_name, O_RDONLY)) == 0)
    return (NULL);
  if ((program = my_malloc(sizeof(t_program), "Error: fail to malloc program...\n")) == 0)
    return (NULL);
  program->prog_param = prog;
  if ((program->header = my_malloc(sizeof(header_t), "Error: fail to malloc header...\n")) == 0)
    return (NULL);
  if (read(fd, program->header, sizeof(header_t)) <= 0)
    return (NULL);
  if (endian_cmp(program->header->magic, COREWAR_EXEC_MAGIC) == 0)
  {
    my_printf("%s: Invalide corewar file ...\n", prog->prog_name);
    return (NULL);
  }
  if (is_big_endian() == 0)
    program->header->prog_size = swap_int(program->header->prog_size);
  if (mem_reader(vm, fd, program) == 1)
  {
    my_printf("Error: invalid prog size expected %s\n", program->header->prog_size);
    return (NULL);
  }
  program->registre[0][REG_SIZE - 1] = (char)prog->prog_number;
  program->pc = prog->load_address;
  program->sleep = 0;
  program->active = 1;
  program->carry = 1;
  program->pid = prog->prog_number;
  vm->register_player[program->pid] = 1;
  return (program);
}

int	load_all_programs(t_vm *vm)
{
  int	i;
  t_prog_param	*prog;
  t_program	*program;

  if ((vm->prog_list = create_list(NULL)) == 0)
    return (1);
  i = 0;
  while (i < vm->param->progs->nb_elm)
  {
    prog = get_data(vm->param->progs, i);
    program = NULL;
    if ((program = load_program(prog, vm)) == 0)
    {
      my_printf("Error: fail to load : %s\n", prog->prog_name);
      return (1);
    }
    add_last_elm(vm->prog_list, program);
    vm->progs_live[program->registre[0][REG_SIZE - 1]] = 0;
    ++i;
  }
  return (0);
}

void	pause_vm(t_vm *vm, int deb)
{
  int	run;
  SDL_Event	event;
  SDL_Surface	*texte;
  SDL_Color	color;
  SDL_Rect	pos;
  char		buff[4096];

  color.r = 255;
  color.g = 255;
  color.b = 255;
  run = 1;
  while (run)
  {
    if (deb != 0)
      SDL_FillRect(vm->screen, NULL, SDL_MapRGB(vm->screen->format, 0, 0, 0));
    my_strcpy(buff, "Appuyer sur une touche pour ");
    my_strcat(buff, deb != 0 ? "commencer" : "terminer");
    if ((texte = TTF_RenderText_Solid(vm->police, buff, color)) == NULL)
      err_TTF();
    pos.x = vm->screen->w / 2 - texte->w / 2;
    pos.y = vm->screen->h / 2 - texte->h / 2;
    SDL_BlitSurface(texte, NULL, vm->screen, &pos);
    SDL_FreeSurface(texte);
    SDL_Flip(vm->screen);
    SDL_WaitEvent(&event);
    if (event.type == SDL_KEYDOWN)
      run = 0;
  }
}

int	launch_vm(t_param *param)
{
  t_vm	*vm;
  int	i;

  if ((vm = my_malloc(sizeof(t_vm), "Error: fail to malloc vm\n")) == 0)
    return (1);
  vm->screen = SDL_SetVideoMode(MEM_SIZE / NB_COL * WIDTH + DECAL, NB_COL * WIDTH, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Corewar", NULL);
  if (vm->screen == NULL)
    err_SDL();
  vm->police = TTF_OpenFont("arial.ttf", 20);
  vm->param = param;
  vm->cycle = 0;
  vm->cycle_to_die = CYCLE_TO_DIE;
  vm->nb_live = 0;
  owner_set(vm->mem_owner, -1, 0, MEM_SIZE);
  my_memset(vm->register_player, 0, (MAX_PLAYER + 1) * sizeof(char));
  i = 0;
  while (i < MAX_PROG_NUMBER)
    vm->progs_live[i++] = -1;
  if (load_all_programs(vm) != 0)
    return (1);
  my_printf("%d program(s) loaded\n", vm->prog_list->nb_elm);
  if (param->debug == 1)
    dump_memory(vm->memory);
  pause_vm(vm, 1);
  vm_run(vm);
  pause_vm(vm, 0);
  if (param->debug == 1)
    dump_memory(vm->memory);
  TTF_CloseFont(vm->police);
  return (0);
}
