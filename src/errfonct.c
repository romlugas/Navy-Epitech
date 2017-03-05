/*
** error.c for navy in /home/rom1/BLINUX/lugas_r/Unix_System_Programmation/NAVY
**
** Made by Romain LUGAS
** Login   <romain.lugas@epitech.eu>
**
** Started on  Thu Feb  9 17:56:03 2017 Romain LUGAS
** Last update Sun Feb 19 19:58:38 2017 Pierre-Malick Boissiere
*/

#include "my.h"

int		check_lenBoat(char *str)
{
  int		res_coord1;
  int		res_coord2;

  res_coord1 = my_get_digit(str[3]) + my_get_digit(str[2] - 16);
  res_coord2 = my_get_digit(str[6]) + my_get_digit(str[5] - 16);
  if ((res_coord1 = (1 + res_coord2 - res_coord1)) == (str[0] - 48))
    return (0);
  else
    return (84);
}

int		check_coordBoat(char *str)
{
  int		i;
  int		cmt;

  i = 2;
  cmt = 0;
  while (str[i])
    {
      if ((str[i] >= '1' && str[i] <= '8') ||
	  (str[i] >= 'A' && str[i] <= 'H'))
	{
	  if (str[i] >= '1' && str[i] <= '8')
	    cmt++;
	  else if (str[i] >= 'A' && str[i] <= 'H')
	    cmt--;
	  i++;
	}
      else if (str[i] == ':' && cmt == 0)
	i++;
      else
	return (84);
    }
  if (cmt == 0)
    return (0);
  else
    return (84);
}

int		template(char *str)
{
  int		error;

  error = 0;
  str = my_strcapitalize(str);
  if (!(str[0] >= '2' && str[0] <= '5'))
    return (84);
  else
    {
      if (!(str[1] == ':' && str[4] == ':'))
	return (84);
      else
	{
	  if ((error = check_coordBoat(str)) == 84)
	    return (84);
	}
    }
  return (0);
}

char		*inverseDigits(char *str)
{
  char		c;

  if (str[2] >= '0' && str[2] <= '9')
    {
      c = str[2];
      str[2] = str[3];
      str[3] = c;
    }
  if (str[5] >= '0' && str[5] <= '9')
    {
      c = str[5];
      str[5] = str[6];
      str[6] = c;
    }
  return (str);
}
