/*
** system_control.c for system_control in /home/clement/Documents/piscine/my_ftl
** 
** Made by LENOURS Clément
** Login   <lenour_c@etna-alternance.net>
** 
** Started on  Tue Nov  8 09:19:16 2016 LENOURS Clément
** Last update Thu Nov 10 14:38:48 2016 LENOURS Clément
*/

#include "my_ftl.h"

void	ftl_drive_system_check(t_ship *ship)
{
  if (ship == NULL)
    return ;
  my_putstr("verification du reacteur en cours...\n");
  if (my_strcmp((ship->ftl_drive)->system_state, "online") == 0)
    my_putstr_color("green", "reacteur OK!\n");
  else
    my_putstr_color("red", "reacteur hors service!\n");
}

void	tools_system_check(t_ship *ship)
{
  if (ship == NULL)
    return ;
  my_putstr("verification du systeme de navigation en cours...\n");
  if (my_strcmp((ship->navigation_tools)->system_state, "online") == 0)
    my_putstr_color("green", "systeme de navigation OK!\n");
  else
    my_putstr_color("red", "systeme de navigation hors service!\n");
}

void	weapon_system_check(t_ship *ship)
{
  if (ship == NULL)
    return ;
  my_putstr("verification du reacteur en cours...\n");
  if (my_strcmp((ship->weapon)->system_state, "online") == 0)
    my_putstr_color("green", "systeme d'armement OK!\n");
  else
    my_putstr_color("red", "systeme d'armement hors service!\n");
}

int	system_control(t_ship *ship)
{
  if (ship == NULL)
    return (0);
  ftl_drive_system_check(ship);
  tools_system_check(ship);
  weapon_system_check(ship);
  return (1);
}
