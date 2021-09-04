/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk_client.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/01 19:29:06 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/04 21:40:39 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static int	is_pid_digit(char *pid)
{
	int	i;

	i = 0;
	while (pid[i] != '\0')
	{
		if (ft_isdigit(pid[i]) == FALSE)
			return (0);
		i++;
	}
	return (1);
}

static void	send_msg_subloop(int pid, char c, int timer)
{
	unsigned char	byte;

	byte = 0b10000000;
	while (byte)
	{
		if ((byte & c) > 0)
			check_kill(kill(pid, SIGUSR2));
		else
			check_kill(kill(pid, SIGUSR1));
		byte = byte >> 1;
		usleep(timer);
	}
	return ;
}

static void	send_msg_loop(int pid, char *msg)
{
	int		i;
	size_t	len;
	int		timer;

	i = 0;
	len = ft_strlen(msg);
	if (len <= 4020)
		timer = 170;
	else if (len > 4020 && len <= 8040)
		timer = 255;
	else
		timer = 330;
	while (msg[i] != '\0')
	{
		send_msg_subloop(pid, msg[i], timer);
		i++;
	}
	send_msg_subloop(pid, msg[i], timer);
	return ;
}

int	main(int argc, char **argv)
{
	int					pid;

	if (argc != 3)
	{
		ft_putstr_fd("Wrong number of arguements\n", 1);
		ft_putstr_fd("The program should be executed as follows;\n", 1);
		ft_putstr_fd("./minitalk_client [PID NUMBER] [MESSAGE]\n", 1);
		return (0);
	}
	if (is_pid_digit(argv[1]) == FALSE)
	{
		ft_putstr_fd("PID Number provided is not even a number.\n", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == ERROR)
		if_kill_returns_zero(pid);
	else
		send_msg_loop(pid, argv[2]);
	ft_putstr_fd("\033[1m\033[32mMessage sent to server!\033[1m\033[39m\n", 1);
	return (0);
}
