/*
** sighandlers.c for navy in /home/boissi_p/rendu/PSU_2016_navy/src
**
** Made by Pierre-Malick Boissiere
** Login   <boissi_p@epitech.net>
**
** Started on  Tue Jan 31 15:54:37 2017 Pierre-Malick Boissiere
** Last update Sun Feb 19 18:42:30 2017 Pierre-Malick Boissiere
*/

#include "my.h"

void		sig_end(int sig)
{
  if (sig == SIGUSR1)
    {
      write(1, "I won\n", 6);
    }
}

void		sig_atk(int sig)
{
  if (sig == SIGUSR1)
    {
      g_ch = 1;
      signal(sig, SIG_IGN);
      write(1, ":   hit\n\n", 9);
    }
  if (sig == SIGUSR2)
    {
      g_ch = 0;
      signal(sig, SIG_IGN);
      write(1, ":   missed\n\n", 12);
    }
}

void		hdlusr(int sig)
{
  if (sig == SIGUSR1)
    {
      g_ch = 1;
      signal(sig, SIG_IGN);
    }
  if (sig == SIGUSR2)
    {
      g_ch = 0;
      signal(sig, SIG_IGN);
    }
}

void		sighandler(int sig)
{
  if (sig == SIGUSR1)
    {
      signal(sig, SIG_IGN);
      write(1, "ennemy connected\n", 17);
    }
  if (sig == SIGUSR2)
    {
      signal(sig, SIG_IGN);
      write(1, "Successfully connected\n", 23);
    }
}

int		sig_getnb(void)
{
  int		nb;
  int		tab[16];
  int		i;

  g_ch = 2;
  nb = 0;
  i = 0;
  while (i != 16)
    {
      signal(SIGUSR1, hdlusr);
      signal(SIGUSR2, hdlusr);
      pause();
      if ((g_ch != 1) || (g_ch != 0))
	tab[i++] = g_ch;
    }
  nb = getnbfrombin(tab);
  return (nb);
}
