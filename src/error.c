/*
** error.c for navy in /home/boissi_p/rendu/PSU_2016_navy/src
**
** Made by Pierre-Malick Boissiere
** Login   <boissi_p@epitech.net>
**
** Started on  Sun Feb 19 17:23:34 2017 Pierre-Malick Boissiere
** Last update Sun Feb 19 23:27:54 2017 Pierre-Malick Boissiere
*/

#include "my.h"

int		map_error(char *str)
{
  int		a;

  str = inverseDigits(str);
  if ((a = get_lenLine(str)) == 84)
    return (84);
  if ((a = template(str)) == 84)
    return (85);
  if ((a = check_lenBoat(str)) == 84)
    return (86);
  if ((a = check_coordBoat(str)) == 84)
    return (87);
  if ((a = diagonal(str)) == 84)
    return (88);
  return (0);
}
