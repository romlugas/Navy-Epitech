/*
** error2.c for navy in /home/rom1/BLINUX/lugas_r/Unix_System_Programmation/NAVY
**
** Made by Romain LUGAS
** Login   <romain.lugas@epitech.eu>
**
** Started on  Sat Feb 11 09:51:49 2017 Romain LUGAS
** Last update Sun Feb 19 18:10:29 2017 Pierre-Malick Boissiere
*/

#include "my.h"

int		my_get_digit(char c)
{
  int		nbr;

  nbr = 0;
  nbr = c - 48;
  return (nbr);
}

int		get_lenLine(char *str)
{
  int		i;

  i = 0;
  i = my_strlen(str);
  if (i != 7)
    return (84);
  return (0);
}

int		diagonal(char *str)
{
  int		i;

  i = 2;
  if (str[i] != str[i + 3])
    {
      i += 1;
      if (str[i] != str[i + 3])
	return (84);
      else
	return (0);
    }
  else
    {
      i += 1;
      if (str[i] == str[i + 3])
	return (84);
      else
	return (0);
    }
}
