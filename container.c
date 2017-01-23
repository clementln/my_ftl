/*
** container.c for container in /home/clement/Documents/piscine/my_ftl
** 
** Made by LENOURS Clément
** Login   <lenour_c@etna-alternance.net>
** 
** Started on  Tue Nov  8 09:18:20 2016 LENOURS Clément
** Last update Sat Nov 12 11:21:38 2016 LENOURS Clément
*/

#include "my_ftl.h"

int		add_container_to_ship(t_ship *ship)
{
  t_container	*container;

  my_putstr("ajout du container en cours...\n");
  if ((container = malloc(sizeof(*container))) == NULL || ship == NULL)
    {
      my_putstr("votre vaisseau a explose lorsque vous avez pose");
      my_putstr(" le container\n");
      return (0);
    }
  container->first = NULL;
  container->last = NULL;
  container->nb_elem = 0;
  container->loaded = 0;
  ship->container = container;
  my_putstr_color("green", "le container a ete ajoute avec succes!\n");
  return (1);
}

void		add_freight_to_container(t_ship *ship, t_freight *freight)
{
  if (ship == NULL || freight == NULL)
    return ;
  if (ship->container->nb_elem == 0)
    {
      freight->next = NULL;
      freight->prev = NULL;
      ship->container->first = freight;
      ship->container->last = freight;
    }
  else
    {
      freight->next = NULL;
      freight->prev = ship->container->last;
      ship->container->last->next = freight;
      ship->container->last = freight;
    }
  ship->container->nb_elem++;
}

void		del_freight_from_container(t_ship *ship, t_freight *freight)
{
  if (ship == NULL || freight == NULL || ship->container->nb_elem == 0 ||
      not_in_container(ship, freight))
    return ;
  if (ship->container->nb_elem == 1)
    {
      ship->container->first = NULL;
      ship->container->last = NULL;
    }
  else if (ship->container->first == freight)
    {
      ship->container->first = freight->next;
      ship->container->first->prev = NULL;
    }
  else if (ship->container->last == freight)
    {
      ship->container->last = freight->prev;
      ship->container->last->next = NULL;
    }
  else
    {
      freight->prev->next = freight->next;
      freight->next->prev = freight->prev;
    }
  ship->container->nb_elem--;
  free(freight->item); free(freight);
}

int		not_in_container(t_ship *ship, t_freight *freight)
{
  t_freight	*temp;

  temp = ship->container->first;
  while (temp != NULL)
    {
      if (temp == freight)
	return (0);
      temp = temp->next;
    }
  free(temp);
  return (1);
}

int		getbonus(t_ship *ship)
{
  if (ship->container->loaded == 0 || ship->container->loaded == 2)
    {
      if (ship->container->loaded == 0)
	my_putstr_color("yellow", "Cargo vide...\n");
      else if (ship->container->loaded == 2)
	my_putstr_color("yellow", "Cargo vide...\n");
      return (0);
    }
  my_putstr("Les bonus ont été ajouté au vaisseau :\n");
  while (ship->container->first != NULL)
    {
      if (my_strcmp(ship->container->first->item, "attackbonus") == 0)
	  ship->weapon->damage += 5;
      else if (my_strcmp(ship->container->first->item, "evadebonus") == 0)
	  ship->navigation_tools->evade += 3;
      else if (my_strcmp(ship->container->first->item, "energy") == 0)
	  ship->ftl_drive->energy++;
      del_freight_from_container(ship, ship->container->first);
    }
  ship->container->loaded = 2;
  stat(ship);
  return (1);
}
