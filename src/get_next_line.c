/*
** get_next_line.c for matchstick in /home/boissi_p/rendu/CPE_2016_matchstick/src
** 
** Made by Pierre-Malick Boissiere
** Login   <boissi_p@epitech.net>
** 
** Started on  Tue Feb 14 17:11:56 2017 Pierre-Malick Boissiere
** Last update Tue Feb 14 17:11:57 2017 Pierre-Malick Boissiere
*/

#include "my.h"

char		*my_realloc(char *str, int size)
{
  char		*s;
  int		i;

  i = 0;
  if (str == NULL)
    return (NULL);
  else
    {
      if ((s = malloc(sizeof(str) + sizeof(char) * size + 1)) == NULL)
	return (NULL);
      if (s != NULL || str != NULL)
	{
	  while (str[i] != '\0')
	    {
	      s[i] = str[i];
	      i += 1;
	    }
	  s[i] = '\0';
	}
      else
	return (NULL);
      free(str);
      return (s);
    }
}

char		reader(const int fd)
{
  static char	buffer[READ_SIZE];
  static int	n = 0;
  static int	res = 0;
  char		c;

  if (res == 0)
    {
      res = read(fd, buffer, READ_SIZE);
      n = 0;
      if (res == 0 || res < 0)
	return (0);
    }
  c = buffer[n];
  n += 1;
  res -= 1;
  return (c);
}

char		*get_next_line(const int fd)
{
  int		i;
  char		c;
  char		*str;

  if ((str = malloc(READ_SIZE + 1)) == NULL)
      return (NULL);
  i = 0;
  c = '0';
  while (c != '\n' && c != '\0' && c != EOF)
    {
      c = reader(fd);
      str[i] = c;
      str[++i] = '\0';
      if (i % (READ_SIZE) == 0)
	if ((str = my_realloc(str, ((READ_SIZE) + (i + 1)))) == NULL)
	  return (NULL);
    }
  str[i - 1] = 0;
  if (c == 0 && str[0] == 0)
    return (NULL);
  return (str);
}
