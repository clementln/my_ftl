/*
** ennemy.c for ennemy in /home/clement/Documents/piscine/my_ftl/lenour_c
** 
** Made by LENOURS Clément
** Login   <lenour_c@etna-alternance.net>
** 
** Started on  Thu Nov 10 11:58:42 2016 LENOURS Clément
** Last update Sat Nov 12 10:54:09 2016 LENOURS Clément
*/

#include "my_ftl.h"

void		*add_ennemy(t_ship *ship)
{
  t_ennemy	*ennemy;

  if ((ennemy = malloc(sizeof(*ennemy))) == NULL)
    return (NULL);
  ennemy->life = (int)(20 * power(1.5, ship->cpt_ennemy));
  ennemy->damage = (int)(10 * power(1.5, ship->cpt_ennemy));
  ship->ennemy = ennemy;
  ship->cpt_ennemy++;
  stat_ennemy(ship);
  return (ship);
}

float		power(float nb, int pow)
{
  if (pow == 0)
    return (1);
  else if (pow > 1)
    return (nb * power(nb, pow - 1));
  return (nb);
}

int		stat_ennemy(t_ship *ship)
{
  if (ship->ennemy ==  NULL)
    {
      my_putstr("Pas d'ennemi présent...\n");
      return (0);
    }
  my_putstr_color("yellow" , "[ENNEMY] : \n");
  my_putstr_color("magenta", " | life : ");
  my_put_nbr(ship->ennemy->life); my_putchar('\n');
  my_putstr_color("magenta", " | damage : ");
  my_put_nbr(ship->ennemy->damage); my_putchar('\n');
  return (0);
}
