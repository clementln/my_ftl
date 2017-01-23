/*
** system_repair.c for system_repair in /home/clement/Documents/piscine/my_ftl
** 
** Made by LENOURS Clément
** Login   <lenour_c@etna-alternance.net>
** 
** Started on  Tue Nov  8 09:18:54 2016 LENOURS Clément
** Last update Sat Nov 12 12:15:14 2016 LENOURS Clément
*/

#include "my_ftl.h"

static const	t_repair_command repair_commands[] = {
  {"ftl_drive", &ftl_drive_system_repair},
  {"navigation_tools", &navigation_tools_system_repair},
  {"weapon", &weapon_system_repair},
  {NULL, NULL}
};

int		ftl_drive_system_repair(t_ship *ship)
{
  if (ship == NULL)
    return (0);
  my_putstr("reparation des reacteurs en cours...\n");
  free((ship->ftl_drive)->system_state);
  if (((ship->ftl_drive)->system_state = my_strdup("online")) == NULL)
    {
      my_putstr("les reparations du reacteur ont echoue\n");
      return (0);
    }
  my_putstr("reparation termine! systeme reacteur OK!\n");
  return (1);
}

int		navigation_tools_system_repair(t_ship *ship)
{
  if (ship == NULL)
    return (0);

  my_putstr("reparation du systeme de navigation en cours...\n");
  free((ship->navigation_tools)->system_state);
  if (((ship->navigation_tools)->system_state = my_strdup("online")) == NULL)
    {
      my_putstr("les reparations des outils de navigations ont echoue\n");
      return (0);
    }
  my_putstr("reparation termine! systeme de navigation OK!\n");
  return (1);
}

int		weapon_system_repair(t_ship *ship)
{
  if (ship == NULL)
    return (0);
  my_putstr("reparation du systeme du systeme d'armement en cours..\n");
  free(ship->weapon->system_state);
  if ((ship->weapon->system_state = my_strdup("online")) == NULL)
    {
      my_putstr("les reparations du systeme d'armement ont echoue\n");
      return (0);
    }
  my_putstr("reparation termine! systeme d'armement OK!\n");
  return (1);
}

int		system_repair(t_ship *ship)
{
  char		*command;
  int		invalid;

  invalid = 1;
  while (invalid)
    {
      my_putstr_color("magenta","repair_system~> ");
      if ((command = readline()) == NULL)
	{
	  my_putstr_color("red", "[SYSTEM FAILURE] : ");
	  my_putstr_color("red", "le lecteur de commande est bloque\n");
	}
      else
	invalid = 0;
    }
  return (detect_repair_cmd(ship, command));
}


int		detect_repair_cmd(t_ship  *ship, char *cmd)
{
  int		idx;

  idx = 0;
  while (idx < 4)
    {
      if (my_strcmp(cmd, repair_commands[idx].repair_command) == 0)
	{
	  repair_commands[idx].repair_command_func(ship);
	  free(cmd);
	  return (1);
	}
      idx++;
    }
  if (my_strcmp(cmd, "clear") == 0)
    my_putstr_color("clear", "");
  else if (my_strcmp(cmd, "help") == 0)
    help_sysrepair();
  else if (my_strcmp(cmd, "quit") == 0)
    return (0);
  else
    my_putstr_color("red", "[SYSTEM FAILURE] : commande inconnue\n");
  free(cmd);
  system_repair(ship);
  return (0);
}
