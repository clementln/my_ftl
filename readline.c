/*
** readline.c for readline in /home/clement/Documents/piscine/my_ftl
** 
** Made by LENOURS Clément
** Login   <lenour_c@etna-alternance.net>
** 
** Started on  Tue Nov  8 09:19:56 2016 LENOURS Clément
** Last update Fri Nov 11 11:26:39 2016 LENOURS Clément
*/
#include	<stdlib.h>
#include	<unistd.h>

char		*readline(void)
{
  ssize_t	ret;
  char		*buff;

  if ((buff = malloc((8192 + 1) * sizeof(char))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  free(buff);
  return (NULL);
}
