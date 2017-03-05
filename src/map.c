/*
** map.c for navy in /home/boissi_p/rendu/PSU_2016_navy/src
** 
** Made by Pierre-Malick Boissiere
** Login   <boissi_p@epitech.net>
** 
** Started on  Mon Jan 30 14:51:04 2017 Pierre-Malick Boissiere
** Last update Sun Feb 19 23:28:09 2017 Pierre-Malick Boissiere
*/

#include "my.h"

char		**fill_boats(char **tab, t_pos pos, int savx, int savy)
{
  while (savx != pos.x)
    tab[savx++][savy] = pos.len;
  while (savy != pos.y)
    tab[savx][savy++] = pos.len;
  return (tab);
}

char		**putBoat(char **tab, char *str, t_pos pos, int i)
{
  int		savx;
  int		savy;
  int		j;

  savx = 0;
  savy = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ':')
	i++;
      if (str[i] >= 'A' && str[i] <= 'H')
	pos.y = str[i++] - 65;
      if (str[i] >= '0' && str[i] <= '8')
	pos.x = str[i++] - 49;
      if (j == 0)
	{
	  savx = pos.x;
	  savy = pos.y;
	}
      tab[pos.x][pos.y] = pos.len;
      j++;
    }
  tab = fill_boats(tab, pos, savx, savy);
  return (tab);
}

char		**getBoats(const int fd, char **tab)
{
  char		*str;
  t_pos		pos;
  int		i;
  int		res;

  i = 2;
  pos.len = 0;
  pos.x = 0;
  pos.y = 0;
  res = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      if ((res = map_error(str)) != 0)
	{
	  free_2D(tab);
	  free(str);
	  return (NULL);
	}
      pos.len = str[0];
      tab = putBoat(tab, str, pos, i);
      free(str);
    }
  return (tab);
}

char		**mapper()
{
  char		**tab;
  int		i;
  int		j;

  i = 0;
  j = 0;
  tab = create_my_2D(8, 8);
  while (tab[i] != NULL)
    {
      while (j != 8)
	tab[i][j++] = '.';
      tab[i][j] = '\0';
      j = 0;
      i += 1;
    }
  return (tab);
}
