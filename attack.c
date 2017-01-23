/*
** attack.c for attack in /home/clement/Documents/piscine/my_ftl/lenour_c
** 
** Made by LENOURS Clément
** Login   <lenour_c@etna-alternance.net>
** 
** Started on  Wed Nov  9 17:34:18 2016 LENOURS Clément
** Last update Sat Nov 12 11:23:05 2016 LENOURS Clément
*/

#include "my_ftl.h"
#include <time.h>

void		ennemy_attack(t_ship *ship, int joue)
{
  int		esq;
  int		sys_rand;

  if (ship->ennemy == NULL || joue == 0)
    return ;
  srand(time(NULL));
  esq = my_rand(100);
  sys_rand = my_rand(100);
  my_putstr("L'ennemi vous attaque !\n");
  if (esq >= 26)
    {
      ship->hull -= ship->ennemy->damage;
      if (sys_rand >= 81)
	loose_sys(ship);
      my_putstr_color("red", "Vous avez été touche! ");
    }
  else
    my_putstr_color("cyan", "Vous n'avez pas ete touche! ");
  my_put_nbr(ship->hull); my_putstr(" pdv restants\n");
}

void		ship_attack(t_ship *ship)
{
  int		nrj_rand;

  srand(time(NULL));
  nrj_rand = my_rand(2);
  if (my_strcmp(ship->weapon->system_state,  "online") != 0)
    {
      my_putstr_color("red", "Votre arme est HS, veuillez la reparer\n");
      return ;
    }
  my_putstr("Vous attaquez l'ennemi... ");
  ship->ennemy->life -= ship->weapon->damage;
  my_put_nbr(ship->ennemy->life); my_putstr(" pdv restants\n");
  if (ship->ennemy->life <= 0)
    {
      my_putstr_color("yellow", "Vous avez detruit le vaisseau ennemi!!\n");
      free(ship->ennemy);
      ship->ennemy = NULL;
    }
  if (nrj_rand == 1)
    {
      my_putstr("Vous avez perdu une unité d'energie...\n");
      ship->ftl_drive->energy--;
    }
}

void		loose_sys(t_ship *ship)
{
  int		rand;

  srand(time(NULL));
  rand = my_rand(3);
  if (rand == 1)
    {
      free(ship->ftl_drive->system_state);
      if ((ship->ftl_drive->system_state = my_strdup("offline")) == NULL)
	  return ;
      my_putstr_color("red", "[ALERT] Votre reacteur a laché..\n");
    }
  else if (rand == 2)
    {
      free(ship->weapon->system_state);
      if ((ship->weapon->system_state = my_strdup("offline")) == NULL)
	return ;
      my_putstr_color("red", "[ALERT] Votre arme a laché..\n");
    }
  else if (rand == 3)
    {
      free(ship->navigation_tools->system_state);
      if ((ship->navigation_tools->system_state = my_strdup("offline")) == NULL)
	return ;
      my_putstr_color("red", "[ALERT] Vos outils de navigation ont lachés\n");
    }
}

