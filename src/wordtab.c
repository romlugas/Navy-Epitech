/*
** wordtab.c for navy in /home/boissi_p/rendu/PSU_2016_navy/src
** 
** Made by Pierre-Malick Boissiere
** Login   <boissi_p@epitech.net>
** 
** Started on  Mon Feb 13 14:14:22 2017 Pierre-Malick Boissiere
** Last update Mon Feb 13 14:14:23 2017 Pierre-Malick Boissiere
*/

#include "my.h"

void		free_2D(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i += 1;
  i -= 1;
  while (i != 0)
    {
      free(tab[i]);
      i -= 1;
    }
  free(tab[i]);
  free(tab);
}

void		display_2D(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      write(1, "\n", 1);
      i += 1;
    }
}

char		**create_my_2D(int line, int column)
{
  char		**tab;
  int		j;

  j = 0;
  if ((tab = malloc((line + 2) * sizeof(char *))) == NULL)
    return (NULL);
  while (j != line)
    {
      if ((tab[j] = malloc((column + 1) * sizeof(char))) == NULL)
	return (NULL);
      tab[j][column] = '\0';
      j = j + 1;
    }
  tab[j] = NULL;
  return (tab);
}

void		disp_my_map(char **tab)
{
  int		i;
  int		j;

  i = 0;
  write(1, "\nmy positions:\n", 15);
  write(1, " |A B C D E F G H\n", 18);
  write(1, "-+---------------\n", 18);
  while (i < 8)
    {
      j = 0;
      my_put_nbr(i + 1);
      write(1, "|", 1);
      while (j < 8)
	{
	  write(1, &tab[i][j], 1);
	  write(1, " ", 1);
	  j++;
	}
      write(1, "\n", 1);
      i++;
    }
}

void		disp_enemy_map(char **tab)
{
  int		i;
  int		j;

  i = 0;
  write(1, "\nenemy's positions:\n", 20);
  write(1, " |A B C D E F G H\n", 18);
  write(1, "-+---------------\n", 18);
  while (i < 8)
    {
      j = 0;
      my_put_nbr(i + 1);
      write(1, "|", 1);
      while (j < 8)
	{
	  write(1, &tab[i][j], 1);
	  write(1, " ", 1);
	  j++;
	}
      write(1, "\n", 1);
      i++;
    }
}
