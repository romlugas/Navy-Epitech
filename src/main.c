/*
** main.c for navy in /home/boissi_p/rendu/PSU_2016_navy
**
** Made by Pierre-Malick Boissiere
** Login   <boissi_p@epitech.net>
**
** Started on  Mon Jan 30 10:31:22 2017 Pierre-Malick Boissiere
** Last update Sun Feb 19 20:47:06 2017 Pierre-Malick Boissiere
*/

#include "my.h"

void		display_usage()
{
  write(1, "USAGE\n", 6);
  write(1, "\t   ./navy [first_player_pid] navy_positions\n\n", 47);
  write(1, "DESCRIPTION\n", 12);
  write(1, "\t   first_player_pid   only for the 2nd player.", 48);
  write(1, " pid of the first player.\n\t   navy_positions", 44);
  write(1, "     file representing the positions of the ships.\n", 51);
}

int		error_handler(int ac, char **av)
{
  if (ac == 1)
    return (-1);
  if (ac == 2  && av[1][0] == '-')
    return (2);
  if (ac == 3)
    return (3);
  if (ac == 2 && av[1][0] != '-')
    return (4);
  else
    return (-1);
}

int		main(int ac, char **av)
{
  int		err;
  int		fd;

  err = 0;
  if ((err = error_handler(ac, av)) != -1)
    {
      if (err == 3 || err == 4)
	{
	  if (ac == 2)
	    fd = open(av[1], O_RDONLY);
	  if (ac == 3)
	    fd = open(av[2], O_RDONLY);
	  if (navy(ac, av, fd) == 84)
	    return (84);
	}
      if (err == 2)
	display_usage();
    }
  else
    return (84);
  return (0);
}
