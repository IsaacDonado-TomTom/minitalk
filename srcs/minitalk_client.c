/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk_client.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/01 19:29:06 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/01 19:33:52 by idonado       ########   odam.nl         */
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

static void	send_msg_subloop(int pid, char c)
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
		usleep(150);
	}
	return ;
}

static void	send_msg_loop(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		send_msg_subloop(pid, msg[i]);
		i++;
	}
	send_msg_subloop(pid, msg[i]);
	return ;
}

static void	success_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)ucontext;
	(void)sig;
	(void)info;
	ft_putstr_fd("\033[1m\033[32mMessage sent!\033[1m\033[39m\n", 1);
	return ;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	success;

	success.sa_sigaction = &success_handler;
	sigaction(SIGUSR1, &success, NULL);
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
	return (0);
}
