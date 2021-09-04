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

#include <minitalk.h>

void	check_kill(int kill_return)
{
	if (kill_return >= 0)
		return ;
	else
	{
		ft_putstr_fd("\033[1m\033[31mError linking processes!\033[1m\033[39m\n", 1);
		exit (errno);
	}
}

void	if_kill_returns_zero(int pid)
{
	ft_putstr_fd("Invalid process ID #", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	exit(0);
	return ;
}

char	*ft_joinchr(char *str, int c, int str_index)
{
	char	*result;
	size_t	i;

	if (str == NULL)
	{
		result = malloc(1);
		result[0] = c;
		return (result);
	}
	result = malloc(ft_strlen(str) + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (i != (size_t)str_index)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = c;
	free(str);
	return (result);
}
