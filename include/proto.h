/*
** proto.h for navy in /home/boissi_p/rendu/PSU_2016_navy
** 
** Made by Pierre-Malick Boissiere
** Login   <boissi_p@epitech.net>
** 
** Started on  Mon Jan 30 10:29:38 2017 Pierre-Malick Boissiere
** Last update Sun Feb 19 23:28:31 2017 Pierre-Malick Boissiere
*/

#ifndef PROTO_H_
# define PROTO_H_
#include <unistd.h>

int	kill(pid_t pid, int sig);
int	usleep(int usec);

int	my_strlen(char *);
void	my_putchar(char);
void	my_putstr(char *);
int	my_getnbr(char *);
void	my_put_nbr(int);
char	*my_strcat(char *, char *);
char	**create_my_2D(int, int);
void	display_2D(char **);
void	free_2D(char **);
int	checker(char *);
char	*my_realloc(char *, int);
char	*get_next_line(const int);
char	*gnl_handler(const int, char [], char *, int);
char	**mapper();
int	navy(int, char **, const int);
int	first_player(char **, char **);
int	second_player(char **, char **, char **);
void	sighandler(int);
void	hdlusr(int);
void	sig_atk(int);
void	sig_end(int);
int	sig_getnb();
int	sender(int, int *);
pid_t	setup();
int	getnbfrombin(int *);
int	*dectobin(int);
int	pidsender(int, int);
int	powa(int, int);
int	pid_handler();
void	disp_my_map(char **);
void	disp_enemy_map(char **);
int	game_state(char **);
char	**getBoats(const int, char **);
void	attacker(char **, int);
int	waiter(char **, char **, int);
int	check_end(char **);
void	displayer(char **, char **);
char	*attack_handler(char *);
int	check_attack(char *);
int	map_error(char *);
char	*inverseDigits(char *);
int	template(char *);
int	check_coordBoat(char *);
int	get_lenLine(char *);
int	my_get_digit(char);
int	check_lenBoat(char *);
int	diagonal(char *);
char	*my_strcapitalize(char *);

#endif /* !PROTO_H_ */
