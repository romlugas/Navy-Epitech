/*
** toolbox.c for navy in /home/boissi_p/rendu/PSU_2016_navy/src
**
** Made by Pierre-Malick Boissiere
** Login   <boissi_p@epitech.net>
**
** Started on  Mon Jan 30 15:06:31 2017 Pierre-Malick Boissiere
** Last update Sun Feb 19 16:28:54 2017 Pierre-Malick Boissiere
*/

#include "my.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int		my_getnbr(char *str)
{
  int		i;
  int		nbr;

  i = 0;
  nbr = 0;
  if (str[i] < '0' && str[i] > '9')
    i = i + 1;
  else
    {
      while (str[i] >= '0' && str[i] <= '9')
	{
	  nbr = ((nbr * 10) + (str[i] - 48));
	  i = i + 1;
	}
    }
  return (nbr);
}

char		*my_strcat(char *dest, char *src)
{
  int		count;
  int		i;

  count = 0;
  i = 0;
  if (dest != NULL && src != NULL)
    {
      while (dest[count] != '\0')
	count += 1;
      while (src[i] != '\0')
	dest[count++] = src[i++];
      dest[count] = '\0';
      return (dest);
    }
  return (dest);
}

void		my_put_nbr(int n)
{
  int		c;

  c = 0;
  if (n < 0)
    {
      write(1, "-", 1);
      n = -n;
    }
  if (n >= 10)
    my_put_nbr(n / 10);
  c = ((n % 10) + '0');
  write(1, &c, 1);
}
