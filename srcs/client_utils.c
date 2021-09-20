/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/01 17:55:22 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/04 19:58:26 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int	is_pid_digit(char *pid)
{
	int	i;

	i = 0;
	while (pid[i] != '\0')
	{
		if (ft_isdigit(pid[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	if_kill_returns_zero(int pid)
{
	ft_putstr_fd("Invalid process ID #", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	exit(0);
	return ;
}
