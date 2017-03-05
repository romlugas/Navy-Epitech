/*
** bytes.c for navy in /home/boissi_p/rendu/PSU_2016_navy/src
**
** Made by Pierre-Malick Boissiere
** Login   <boissi_p@epitech.net>
**
** Started on  Mon Feb  6 16:25:46 2017 Pierre-Malick Boissiere
** Last update Thu Feb  9 21:37:55 2017 Pierre-Malick Boissiere
*/

#include "my.h"

int		powa(int nb, int pow)
{
  int		i;
  int		save;

  i = 0;
  save = nb;
  if (pow == 0)
    return (1);
  if (pow == 1)
    return (nb);
  while ((i + 1) != pow)
    {
      nb = nb * save;
      i += 1;
    }
  return (nb);
}

int		getnbfrombin(int *tab)
{
  int		i;
  int		j;
  int		res;

  i = 0;
  j = 0;
  res = 0;
  while (j != 16)
    {
      if (tab[i] == 1)
	res = res + powa(2, j);
      i += 1;
      j += 1;
    }
  return (res);
}

int		*dectobin(int nb)
{
  int		save;
  int		*tab;
  int		i;

  i = 0;
  save = nb;
  while ((save / 10) != 0)
    {
      save = save / 10;
      i += 1;
    }
  tab = malloc(sizeof(int) * (17));
  tab[16] = 2;
  while (i != 16)
    tab[i++] = 2;
  save = nb;
  i = 0;
  while (i != 16)
    {
      tab[i] = save % 2;
      save = save / 2;
      i += 1;
    }
  return (tab);
}
