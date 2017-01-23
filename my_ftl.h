/*
** my_ftl.h for my_ftl in /home/clement/Documents/piscine/my_ftl
** 
** Made by LENOURS Clément
** Login   <lenour_c@etna-alternance.net>
** 
** Started on  Tue Nov  8 09:24:41 2016 LENOURS Clément
** Last update Sat Nov 12 10:51:43 2016 LENOURS Clément
*/

#ifndef _MY_FTL_H_
#define _MY_FTL_H_
#include <stdlib.h>
#include <time.h>

typedef struct		s_weapon
{
  char			*system_state;
  int			damage;
}			t_weapon;

typedef struct	        s_ftl_drive
{
  char			*system_state;
  int			energy;
}			t_ftl_drive;

typedef struct	       	s_navigation_tools
{
  char			*system_state;
  int			sector;
  int			evade;
}			t_navigation_tools;

typedef struct		s_freight
{
  char			*item;
  struct s_freight	*next;
  struct s_freight	*prev;
}			t_freight;

typedef struct		s_container
{
  t_freight		*first;
  t_freight		*last;
  int			nb_elem;
  int			loaded;
}			t_container;

typedef struct		s_ennemy
{
  int			damage;
  int			life;
}			t_ennemy;

typedef struct		s_ship
{
  int			hull;
  t_weapon		*weapon;
  t_ftl_drive		*ftl_drive;
  t_navigation_tools	*navigation_tools;
  t_container		*container;
  t_ennemy		*ennemy;
  int			cpt_ennemy;
}			t_ship;

typedef int (*repair_command_f)(t_ship*);
typedef int (*action_command_f)(t_ship*);

typedef struct		s_repair_command
{
  char			*repair_command;
  repair_command_f	repair_command_func;
}			t_repair_command;

typedef struct		s_action_command
{
  char			*action_command;
  action_command_f	action_command_func;
}			t_action_command;

t_ship			*create_ship();
int			add_weapon_to_ship(t_ship *ship);
int			add_ftl_drive_to_ship(t_ship *ship);
int			add_navigation_tools_to_ship(t_ship *ship);
int			add_container_to_ship(t_ship *ship);
void			add_freight_to_container(t_ship *ship, t_freight *freight);
void			del_freight_from_container(t_ship *ship, t_freight *freight);
void			*add_ennemy(t_ship *ship);
int			getbonus(t_ship *ship);
void			ftl_drive_system_check(t_ship *ship);
void			tools_system_check(t_ship *ship);
void			weapon_system_check(t_ship *ship);
int			system_control(t_ship *ship);
int			ftl_drive_system_repair(t_ship *ship);
int			navigation_tools_system_repair(t_ship *ship);
int			weapon_system_repair(t_ship *ship);
int			system_repair(t_ship *ship);
int			not_in_container(t_ship *ship,  t_freight *freight);
void			my_putchar(const char c);
void			my_putstr(const char *str);
int			my_strcmp(const char *s1, const char *s2);
char			*my_strdup(const char *str);
void			my_putstr_color(const char *color, const char *str);
char			*readline(void);
int			do_action(t_ship *ship);
int			attack(t_ship *ship);
void			ennemy_attack(t_ship *ship, int joue);
void			ship_attack(t_ship *ship);
void			loose_sys(t_ship *ship);
int			stat_ennemy(t_ship *ship);
int			detect(t_ship *ship);
int			stat(t_ship *ship);
int			jump(t_ship *ship);
int			detect_repair_cmd(t_ship *ship, char *cmd);
int			detect_action_cmd(t_ship *ship, char *cmd);
void			my_put_nbr(int nb);
int			my_rand(int mod);
void			clean(t_ship *ship);
float			power(float nb, int pow);
void			asciiart();
void			put_bonus(t_freight *freight, int scrap_rand, int bonus_rand);
int			help();
void			help_sysrepair();

#endif
