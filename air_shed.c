/*
** air_shed.c for air_shed in /home/clement/Documents/piscine/my_ftl
** 
** Made by LENOURS Clément
** Login   <lenour_c@etna-alternance.net>
** 
** Started on  Tue Nov  8 09:18:04 2016 LENOURS Clément
** Last update Sat Nov 12 09:05:43 2016 LENOURS Clément
*/

#include "my_ftl.h"

t_ship		*create_ship()
{
  t_ship	*ship;

  my_putstr("construction du vaisseau en cours...\n");
  if ((ship = malloc(sizeof(*ship))) == NULL)
    {
      my_putstr("le vaisseau n'a pas pu etre construit");
      my_putstr(" par manque de materiaux\n");
      return (NULL);
    }
  ship->hull = 50;
  ship->weapon = NULL;
  ship->ftl_drive = NULL;
  ship->navigation_tools = NULL;
  ship->container = NULL;
  ship->ennemy = NULL;
  ship->cpt_ennemy = 0;
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);
  my_putstr_color("cyan", "amelioration du vaisseau termine!\n\n");
  return (ship);
}

int		add_weapon_to_ship(t_ship *ship)
{
  t_weapon	*weapon;

  my_putstr("ajout des armes en cours...\n");
  if ((weapon = malloc(sizeof(*weapon))) == NULL || ship == NULL)
    {
      my_putstr("votre vaisseau a explosé quand");
      my_putstr(" vous avez tenté d'ajouter les armes\n");
      return (0);
    }
  weapon->damage = 10;
  weapon->system_state = my_strdup("online");
  ship->weapon = weapon;
  my_putstr_color("green", "les armes ont ete ajoutes avec succes!\n");
  return (1);
}

int		add_ftl_drive_to_ship(t_ship *ship)
{
  t_ftl_drive	*ftl_drive;

  my_putstr("ajout du reacteur en cours...\n");
  if ((ftl_drive = malloc(sizeof(*ftl_drive))) == NULL || ship == NULL)
    {
      my_putstr("votre a explose lorsque vous avez pose le reacteur\n");
      return (0);
    }
  ftl_drive->energy = 10;
  ftl_drive->system_state = my_strdup("online");
  ship->ftl_drive = ftl_drive;
  my_putstr_color("green", "le reacteur a ete ajoute avec succes!\n");
  return (1);
}

int		add_navigation_tools_to_ship(t_ship *ship)
{
  t_navigation_tools *navigation_tools;

  my_putstr("ajout des outils de navigations...\n");
  if ((navigation_tools = malloc(sizeof(*navigation_tools))) == NULL ||
      ship == NULL)
    {
      my_putstr("votre a explose lorsque vous avez pose les");
      my_putstr(" outils de navigations\n");
      return (0);
    }
  navigation_tools->sector = 0;
  navigation_tools->evade = 25;
  navigation_tools->system_state = my_strdup("online");
  ship->navigation_tools = navigation_tools;
  my_putstr_color("green", "les outils de navigations");
  my_putstr_color("green", " ont ete ajoute avec succes!\n");
  return (1);
}
