/*
** my_put_nbr.c for my_put_nbr in /home/clement/Documents/piscine/jc5/my_put_nbr
** 
** Made by LENOURS Clément
** Login   <lenour_c@etna-alternance.net>
** 
** Started on  Fri Oct 21 22:44:10 2016 LENOURS Clément
** Last update Fri Nov 11 17:43:10 2016 LENOURS Clément
*/

#include "my_ftl.h"

int	size(int n);
int	pui(int nb, int pow);
void	my_putchar(char c);

void	my_put_nbr(int nbr)
{
  long	l_nbr;

  l_nbr = (long)nbr;
  if (l_nbr < 0)
    {
      my_putchar('-');
      l_nbr = l_nbr * (-1);
    }
  if (l_nbr / 10 != 0)
    my_put_nbr(l_nbr / 10);
  my_putchar((l_nbr % 10) + 48);
}

int	size(int n)
{
  int	i_taille;

  i_taille = 0;
  if (n == 0)
    return (1);
  else if (n < 0)
    i_taille = i_taille + 1;
  while (n != 0)
    {
      n = n / 10;
      i_taille = i_taille + 1;
    }
  return (i_taille);
}

int	pui(int nbr, int pow)
{
  int	i_index;
  int	i_nbr;

  i_index = 1;
  i_nbr = nbr;
  while (i_index < pow)
    {
      i_nbr = i_nbr * nbr;
      i_index = i_index + 1;
    }
  return (i_nbr);
}
