/*
** game.c for navy in /home/boissi_p/rendu/PSU_2016_navy/src
** 
** Made by Pierre-Malick Boissiere
** Login   <boissi_p@epitech.net>
** 
** Started on  Thu Feb  9 14:05:20 2017 Pierre-Malick Boissiere
** Last update Sun Feb 19 16:25:49 2017 Pierre-Malick Boissiere
*/

#include "my.h"

int		game_state(char **tab)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (tab[i] != NULL)
    {
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] >= '0' && tab[i][j] <= '9')
	    return (1);
	  j += 1;
	}
      j = 0;
      i += 1;
    }
  return (0);
}

int		check_end(char **tab)
{
  int		i;
  int		j;
  int		res;

  i = 0;
  j = 0;
  res = 0;
  while (tab[i] != NULL)
    {
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] == 'x')
	    res += 1;
	  j += 1;
	}
      j = 0;
      i += 1;
    }
  if (res == 14)
    return (1);
  else
    return (0);
}

void		displayer(char **tab, char **tab2)
{
  disp_my_map(tab);
  disp_enemy_map(tab2);
}

