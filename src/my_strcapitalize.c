/*
** my_strcapitalize.c for day6 in /home/boissi_p/rendu/CPool_Day06
** 
** Made by Pierre-Malick Boissiere
** Login   <boissi_p@epitech.net>
** 
** Started on  Mon Oct 10 15:33:37 2016 Pierre-Malick Boissiere
** Last update Mon Oct 10 16:20:24 2016 Pierre-Malick Boissiere
*/

char		*my_strcapitalize(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[0] >= 'a' && str[0] <= 'z')
      str[0] = str[0] - 32;
    if (str[i] <= 'a' || str[i] >= 'z')
      if (str[i] <= 'A' || str[i] >= 'Z')
	if (str[i] <= '0' || str[i] >= '9')
	  if (str[i+1] >= 'a' && str[i+1] <= 'z')
	    {
	      str[i+1] = str[i+1] - 32;
	      i = i + 1;
	    }
    i = i + 1;
  }
  return (str);
}
