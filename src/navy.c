/*
** navy.c for navy in /home/boissi_p/rendu/PSU_2016_navy/src
**
** Made by Pierre-Malick Boissiere
** Login   <boissi_p@epitech.net>
**
** Started on  Mon Jan 30 11:11:02 2017 Pierre-Malick Boissiere
** Last update Sun Feb 19 22:34:31 2017 Pierre-Malick Boissiere
*/

#include "my.h"

pid_t		setup()
{
  pid_t		pid;

  pid = getpid();
  write(1, "my_pid:   ", 10);
  my_put_nbr(pid);
  write(1, "\n", 1);
  return (pid);
}

int		first_player(char **tab, char **tab2)
{
  int		my_pid;
  int		his_pid;

  my_pid = setup();
  my_pid = my_pid;
  write(1, "waiting for ennemy connexion...\n", 32);
  his_pid = pid_handler();
  while (game_state(tab) == 1)
    {
      displayer(tab, tab2);
      attacker(tab2, his_pid);
      displayer(tab, tab2);
      if (check_end(tab2) == 1)
	{
	  write(1, "\nI won\n", 7);
	  pidsender(40000, his_pid);
	  return (1);
	}
      if ((waiter(tab, tab2, his_pid)) == 0)
	return (0);
    }
  return (0);
}

int		second_player(char **av, char **tab, char **tab2)
{
  int		my_pid;
  int		his_pid;

  my_pid = setup();
  his_pid = my_getnbr(av[1]);
  pidsender(my_pid, his_pid);
  signal(SIGUSR2, sighandler);
  pause();
  while (game_state(tab) == 1)
    {
      displayer(tab, tab2);
      if (check_end(tab2) == 1)
	{
	  write(1, "I won\n", 6);
	  pidsender(40000, his_pid);
	  return (1);
	}
      if ((waiter(tab, tab2, his_pid)) == 0)
	return (0);
      displayer(tab, tab2);
      if (game_state(tab) == 0)
	return (0);
      attacker(tab2, his_pid);
    }
  return (0);
}

int		navy(int ac, char **av, const int fd)
{
  char		**tab;
  char		**tab2;

  if (ac == 2)
    {
      tab = mapper();
      if ((tab = getBoats(fd, tab)) == NULL)
	return (84);
      tab2 = mapper();
      if ((first_player(tab, tab2)) == 0)
	write(1, "\nEnemy won\n", 11);
    }
  if (ac == 3)
    {
      tab = mapper();
      if ((tab = getBoats(fd, tab)) == NULL)
	return (84);
      tab2 = mapper();
      if ((second_player(av, tab, tab2)) == 0)
	write(1, "\nEnemy won\n", 11);
    }
  free_2D(tab);
  free_2D(tab2);
  close(fd);
  return (0);
}
