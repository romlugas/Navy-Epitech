/*
** communication.c for navy in /home/boissi_p/rendu/PSU_2016_navy/src
**
** Made by Pierre-Malick Boissiere
** Login   <boissi_p@epitech.net>
**
** Started on  Tue Jan 31 15:56:45 2017 Pierre-Malick Boissiere
** Last update Sun Feb 19 16:43:59 2017 Pierre-Malick Boissiere
*/

#include "my.h"

int		sender(int pid, int *tab)
{
  int		i;

  i = 0;
  while (tab[i] != 2)
    {
      usleep(2000);
      if (tab[i] == 1)
	kill(pid, SIGUSR1);
      if (tab[i] == 0)
	kill(pid, SIGUSR2);
      i += 1;
    }
  return (0);
}

int		pidsender(int my_pid, int his_pid)
{
  int		*tab;

  kill(his_pid, SIGUSR1);
  tab = dectobin(my_pid);
  sender(his_pid, tab);
  signal(SIGUSR2, sighandler);
  free(tab);
  return (0);
}

int		pid_handler()
{
  int		pid2;

  signal(SIGUSR1, sighandler);
  pause();
  pid2 = sig_getnb();
  usleep(2000);
  kill(pid2, SIGUSR2);
  return (pid2);
}

char		*attack_handler(char *str)
{
  int		i;
  char		c;

  i = 0;
  if (str[0] >= '0' && str[0] <= '9')
    {
      c = str[0];
      str[0] = str[1];
      str[1] = c;
    }
  if (str[i] >= 'a' && str[i] <= 'h')
    str[i] = str[i] - 32;
  my_putstr(str);
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'H')
	str[i] = str[i] - 17;
      i += 1;
    }
  return (str);
}

int		check_attack(char *str)
{
  char		c;

  if (str[0] >= '0' && str[0] <= '9')
    {
      c = str[0];
      str[0] = str[1];
      str[1] = c;
    }
  if (str[0] >= 'a' && str[0] <= 'z')
    str[0] = str[0] - 32;
  if ((str[0] < 'A') || (str[0] > 'H'))
    return (1);
  if ((str[1] < '1') || (str[1] > '8'))
    return (1);
  return (0);
}
