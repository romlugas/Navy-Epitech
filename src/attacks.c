/*
** attacks.c for navy in /home/boissi_p/rendu/PSU_2016_navy/src
** 
** Made by Pierre-Malick Boissiere
** Login   <boissi_p@epitech.net>
** 
** Started on  Thu Feb  9 21:48:40 2017 Pierre-Malick Boissiere
** Last update Sun Feb 19 16:50:24 2017 Pierre-Malick Boissiere
*/

#include "my.h"

void		marker_two(int nb, char **tab)
{
  int		x;
  int		y;

  x = (nb % 10) - 1;
  y = (nb / 10);
  if ((tab[x][y] >= '0' && tab[x][y] <= '9') || (tab[x][y] == 'x'))
   tab[x][y] = 'x';
 else
   tab[x][y] = 'o';
}

void		marker_one(int nb, char **tab)
{
  int		x;
  int		y;

  x = (nb % 10) - 1;
  y = (nb / 10);
 if (g_ch == 1)
   tab[x][y] = 'x';
 else
   tab[x][y] = 'o';
}

int		mark(char **tab, int nb, int his_pid)
{
  int		x;
  int		y;

  x = (nb % 10) - 1;
  y = (nb / 10);
  if (tab[x][y] >= '0' && tab[x][y] <= '9')
    {
      kill(his_pid, SIGUSR1);
      return (1);
    }
  else
    {
      kill(his_pid, SIGUSR2);
      return (0);
    }
}

void		attacker(char **tab2, int his_pid)
{
  char          *str;
  int           *tabby;

  write(1, "\nattack:   ", 11);
  if ((str = get_next_line(0)) != NULL)
    {
      while ((my_strlen(str) != 2) || (check_attack(str) == 1))
	{
	  write(1, "wrong position", 14);
	  write(1, "\nattack:   ", 11);
	  str = get_next_line(0);
	}
      str = attack_handler(str);
      tabby = dectobin(my_getnbr(str));
      sender(his_pid, tabby);
      signal(SIGUSR1, sig_atk);
      signal(SIGUSR2, sig_atk);
      pause();
      marker_one(my_getnbr(str), tab2);
      free(str);
      free(tabby);
    }
}

int		waiter(char **tab, char **tab2, int his_pid)
{
  int		nb;
  char		c;
  char		d;

  nb = 0;
  tab2 = tab2;
  nb = sig_getnb();
  if (nb == 40000)
    return (0);
  write(1, "\nwaiting for enemy's attack...\n", 31);
  c = (nb / 10) + 17 + 48;
  d = nb % 10 + 48;
  write(1, &c, 1);
  write(1, &d, 1);
  write(1, ":   ", 4);
  if (mark(tab, nb, his_pid) == 1)
    write(1, "hit\n\n", 5);
  else
    write(1, "missed\n\n", 8);
  marker_two(nb, tab);
  return (1);
}
