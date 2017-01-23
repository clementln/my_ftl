/*
** my_rand.c for my_rand in /home/clement/Documents/piscine/projet_c_2/lenour_c/roulette
** 
** Made by LENOURS Clément
** Login   <lenour_c@etna-alternance.net>
** 
** Started on  Sat Oct 22 09:07:40 2016 LENOURS Clément
** Last update Wed Nov  9 11:39:25 2016 LENOURS Clément
*/

#include <stdlib.h>

int	my_rand(int limit)
{
  return ((rand() % limit) + 1);
}
