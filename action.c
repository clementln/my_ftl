/*
** action.c for action in /home/clement/Documents/piscine/my_ftl/lenour_c
** 
** Made by LENOURS Clément
** Login   <lenour_c@etna-alternance.net>
** 
** Started on  Wed Nov  9 09:26:21 2016 LENOURS Clément
** Last update Sat Nov 12 11:25:51 2016 LENOURS Clément
*/

#include "my_ftl.h"

static const	t_action_command action_commands[] = {
  {"detect",&detect},
  {"getbonus",&getbonus},
  {"controlsystem",&system_control},
  {"repairsystem",&system_repair},
  {"stat",&stat},
  {"stat_ennemy", &stat_ennemy},
  {"jump", &jump},
  {"attack", &attack},
  {"help", &help},
  {NULL, NULL}
};

int		do_action(t_ship *ship)
{
  char		*command;

  if ((command = readline()) == NULL)
    {
      my_putstr_color("red", "[SYSTEM FAILURE] : ");
      my_putstr_color("red", "le lecteur de commande est bloque\n");
      return (1);
    }
  return (detect_action_cmd(ship, command));
}

int		detect_action_cmd(t_ship *ship, char *cmd)
{
  int		idx;

  idx = 0;
  while (idx < 9)
    {
      if (my_strcmp(cmd, action_commands[idx].action_command) == 0)
	{
	  action_commands[idx].action_command_func(ship);
	  free(cmd);
	  return (1);
	}
      idx++;
    }
  if (my_strcmp(cmd, "clear") == 0)
    my_putstr_color("clear", "");
  else if (my_strcmp(cmd, "quit") == 0)
    {
      free(cmd);
      return (0);
    }
  else
    my_putstr_color("red", "[SYSTEM FAILURE] : commande inconnue\n");
  free(cmd);
  return (1);
}
