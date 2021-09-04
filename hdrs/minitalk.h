/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 17:14:57 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/04 19:54:04 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define FALSE 0
# define TRUE 1
# define ERROR -1
# define CHAR_BITS 8

# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <signal.h>
# include <errno.h>

typedef struct s_sig_data
{
	char	*buffer;
	char	temp_char;
	int		sender_pid;
	int		str_index;
	int		index;
}				t_sig_data;

void	check_kill(int kill_return);
void	if_kill_returns_zero(int pid);
char	*ft_joinchr(char *str, int c, int index);
#endif