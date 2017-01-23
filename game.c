/*
** game.c for game in /home/clement/Documents/piscine/my_ftl/lenour_c
** 
** Made by LENOURS Clément
** Login   <lenour_c@etna-alternance.net>
** 
** Started on  Wed Nov  9 09:55:51 2016 LENOURS Clément
** Last update Sat Nov 12 10:59:25 2016 LENOURS Clément
*/

#include "my_ftl.h"
#include <time.h>

int		attack(t_ship *ship)
{
  if (ship->ennemy == NULL)
    {
      my_putstr("Pas d'ennemi a proximite...\n");
      return (1);
    }
  ship_attack(ship);
  return (0);
}

int		detect(t_ship *ship)
{
  t_freight	*freights[10];
  int		idx;
  int		scrap_rand;
  int		bonus_rand;

  srand(time(NULL));
  if (my_strcmp(ship->navigation_tools->system_state, "online") != 0)
    {
      my_putstr_color("red", "Veuillez réparer vos outils de navigations..\n");
      return (1);
    }
  if (ship->container->loaded == 1 || ship->container->loaded == 2)
    {
      my_putstr_color("yellow", "Vous avez déjà trouvé des bonus...\n");
      return (1);
    }
  idx = -1;
  while (idx++ < 10)
    {
      scrap_rand = my_rand(10);
      bonus_rand = my_rand(100);
      if ((freights[idx] = malloc(sizeof(*freights[idx]))) == NULL)
	return (1);
      put_bonus(freights[idx], scrap_rand, bonus_rand);
      add_freight_to_container(ship, freights[idx]);
    }
  ship->container->loaded = 1;
  return (0);
}

void		put_bonus(t_freight *freight, int scrap_rand, int bonus_rand)
{
  if ((scrap_rand >= 1 && scrap_rand <= 7) || bonus_rand == 100)
    freight->item = my_strdup("scrap");
  else if (bonus_rand >= 1 && bonus_rand <= 33)
    {
      freight->item = my_strdup("attackbonus");
      my_putstr("Un bonus d'attaque a été trouvé ! ");
      my_putstr_color("magenta","+5"); my_putchar('\n');
    }
  else if (bonus_rand >= 34 && bonus_rand <= 66)
    {
      freight->item = my_strdup("evadebonus");
      my_putstr("Un bonus d'esquive a été trouvé ! ");
      my_putstr_color("magenta","+3"); my_putchar('\n');
    }
  else if (bonus_rand >= 67 && bonus_rand <= 99)
    {
      freight->item = my_strdup("energy");
      my_putstr("Un bonus d'energie a été trouvé ! ");
      my_putstr_color("magenta","+1"); my_putchar('\n');
    }
}

int		stat(t_ship *ship)
{
  my_putstr_color("yellow", "space_ship statement:\n");
  my_putstr_color("magenta", " | hull : ");
  my_put_nbr(ship->hull);
  my_putstr_color("magenta", "\n | damage : ");
  my_put_nbr(ship->weapon->damage);
  my_putstr_color("magenta", "\n | energy : ");
  my_put_nbr(ship->ftl_drive->energy);
  my_putstr_color("magenta", "\n | sector : ");
  my_put_nbr(ship->navigation_tools->sector);
  my_putstr_color("magenta", "\n | evade : ");
  my_put_nbr(ship->navigation_tools->evade);
  my_putchar('\n');
  return (0);
}

int		jump(t_ship *ship)
{
  int	rand;

  srand(time(NULL));
  if (ship->ennemy != NULL ||
      my_strcmp(ship->ftl_drive->system_state, "online") != 0)
    {
      if (ship->ennemy != NULL)
	my_putstr_color("yellow", "Un ennemi vous retient dans ce secteur!!\n");
      if (my_strcmp(ship->ftl_drive->system_state, "online") != 0)
	my_putstr_color("red", "Veuillez réparer votre réacteur\n");
       return (0);
    }
  my_putstr_color("cyan", "Jump !\n\n----- Secteur ");
  my_put_nbr(++(ship->navigation_tools->sector));
  my_putstr_color("cyan", " -----\n\n");
  rand = my_rand(10); ship->ftl_drive->energy--;
  while (ship->container->first != NULL)
    del_freight_from_container(ship, ship->container->first);
  ship->container->loaded = 0;
  if (rand >= 1 && rand <= 3)
    {
      my_putstr_color("red", "[SYSTEM DETECT] Ennemi detecte!\n");
      add_ennemy(ship);
      return (1);
    }
  my_putstr_color("cyan", "[SYSTEM DETECT] Aucun ennemi detecte!\n");
  return (0);
}
