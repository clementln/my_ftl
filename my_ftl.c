/*
** my_ftl.c for my_ftl in /home/clement/Documents/piscine/my_ftl/lenour_c
** 
** Made by LENOURS Clément
** Login   <lenour_c@etna-alternance.net>
** 
** Started on  Tue Nov  8 10:06:34 2016 LENOURS Clément
** Last update Sat Nov 12 12:13:03 2016 LENOURS Clément
*/

#include "my_ftl.h"

int		main()
{
  t_ship	*ship;
  int		joue = 1;

  asciiart();
  ship = create_ship();
  help();
  while (ship->navigation_tools->sector < 10 &&
	 ship->ftl_drive->energy > 0 && ship->hull > 0 &&
	 joue == 1)
    {
      my_putstr_color("magenta","ftl (");
      my_putstr_color("cyan", "Secteur ");
      my_put_nbr(ship->navigation_tools->sector);
      my_putstr_color("magenta", ") ~> ");
      joue = do_action(ship);
      ennemy_attack(ship, joue);
    }
  if (joue == 0)
    my_putstr_color("yellow", "A bientot !\n");
  else if (ship->navigation_tools->sector == 10)
    my_putstr_color("yellow", "Vous avez atteint le secteur 10, bravo!\n");
  else
    my_putstr_color("yellow", "Votre vaisseau a explosé, vous avez perdu\n");
  clean(ship);
  return (0);
}

void		asciiart()
{
  my_putstr_color("clear", "");
  my_putstr_color("yellow", "   __    __    __      __                ");
  my_putstr_color("yellow", "_________   ________   _____      \n");
  my_putstr_color("yellow", "   \\ \\  / /    ) \\    / (               ");
  my_putstr_color("yellow", "(_   _____) (___  ___) (_   _)     \n");
  my_putstr_color("yellow", "   () \\/ ()     \\ \\  / /                  ");
  my_putstr_color("yellow", ") (___        ) )      | |       \n");
  my_putstr_color("yellow", "   / _  _ \\      \\ \\/ /                  ");
  my_putstr_color("yellow", "(   ___)      ( (       | |       \n");
  my_putstr_color("yellow", "  / / \\/ \\ \\      \\  /                    ");
  my_putstr_color("yellow", ") (           ) )      | |   __  \n");
  my_putstr_color("yellow", " /_/      \\_\\      )(      ___________   ");
  my_putstr_color("yellow", "(   )         ( (     __| |___) ) \n");
  my_putstr_color("yellow", "(/          \\)    /__\\    |___________|   ");
  my_putstr_color("yellow", "\\_/          /__\\    \\________/  \n\n");
}

int		help()
{
  my_putstr_color("cyan", "Commandes disponibles :\n");
  my_putstr_color("yellow", "help          ");
  my_putstr(": Affiche la liste des commandes disponibles\n");
  my_putstr_color("yellow", "stat          ");
  my_putstr(": Affiche les statistiques de votre vaisseau\n");
  my_putstr_color("yellow", "stat_ennemy   ");
  my_putstr(": Affiche les statistiques de votre ennemi\n");
  my_putstr_color("yellow", "detect        ");
  my_putstr(": Cherche des bonus dans le secteur (1 fois par secteur)\n");
  my_putstr_color("yellow", "getbonus      ");
  my_putstr(": Ajoute les bonus trouvé au vaisseau\n");
  my_putstr_color("yellow", "attack        ");
  my_putstr(": Attaque un ennemi Lorsque celui-ci ");
  my_putstr("est présent dans le secteur\n");
  my_putstr_color("yellow", "controlsystem ");
  my_putstr(": Affiche l'état des systèmes du vaisseau\n");
  my_putstr_color("yellow", "repairsystem  ");
  my_putstr(": Affiche un prompt de reparation des systèmes du vaisseau\n");
  my_putstr_color("yellow", "jump          ");
  my_putstr(": Permet de changer de secteur (aucun ennemi ne doit se ");
  my_putstr("trouver dans la zone)\n");
  my_putstr_color("yellow", "quit          ");
  my_putstr(": Quitte la partie en cours\n\n");
  return (0);
}

void		help_sysrepair()
{
  my_putstr_color("cyan", "Commandes disponibles :\n");
  my_putstr_color("yellow", "help             ");
  my_putstr(": Affiche la liste des commandes disponibles\n");
  my_putstr_color("yellow", "weapon           ");
  my_putstr(": Répare le système d'armement du vaisseau\n");
  my_putstr_color("yellow", "ftl_drive        ");
  my_putstr(": Répare le réacteur du vaisseau\n");
  my_putstr_color("yellow", "navigation_tools ");
  my_putstr(": Répare le système de navigation du vaisseau\n");
  my_putstr_color("yellow", "quit             ");
  my_putstr(": Quitte le programme de réparation du vaisseau\n\n");
}

void		clean(t_ship *ship)
{
  free(ship->weapon->system_state);
  free(ship->weapon);
  free(ship->ftl_drive->system_state);
  free(ship->ftl_drive);
  free(ship->navigation_tools->system_state);
  free(ship->navigation_tools);
  free(ship->ennemy);
  while (ship->container->first != NULL)
    del_freight_from_container(ship, ship->container->first);
  free(ship->container);
  free(ship);
}
