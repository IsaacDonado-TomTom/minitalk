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

#include <client.h>

static void	safe_exit(char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("Unexpected error.\n", 2);
	exit(-1);
}

int	set_end(int pid, char *str)
{
	static int	i = 0;

	if (i++ != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			safe_exit(str);
		return (0);
	}
	return (1);
}

static int	send_bit(int pid, char *msg)
{
	static char	*s_str = 0;
	static int	s_pid = 0;
	static int	s_bits = -1;

	if (msg)
		s_str = ft_strdup(msg);
	if (s_str == NULL)
		safe_exit(0);
	if (pid)
		s_pid = pid;
	if (s_str[++s_bits / 8])
	{
		if (s_str[s_bits / 8] & (0b10000000 >> (s_bits % 8)))
		{
			if (kill(s_pid, SIGUSR2) == -1)
				safe_exit(s_str);
		}
		else if (kill(s_pid, SIGUSR1) == -1)
			safe_exit(s_str);
		return (0);
	}
	if (!set_end(s_pid, s_str))
		return (0);
	free(s_str);
	return (1);
}

static void	signal_handler(int sig)
{
	int	last_byte;

	last_byte = 0;
	if (sig == SIGUSR1)
		last_byte = send_bit(0, 0);
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("Unexpected Error!\n", 1);
		exit(-1);
	}
	if (last_byte == 1)
	{
		ft_putstr_fd("Message sent!\n", 1);
		exit(0);
	}
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
	if (is_pid_digit(argv[1]) == 0)
	{
		ft_putstr_fd("PID Number provided is not even a number.\n", 1);
		return (0);
	}
	signal(SIGUSR1, signal_handler);
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
		if_kill_returns_zero(pid);
	send_bit(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
