/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk_server.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 16:46:02 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/04 21:10:59 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static void	check_kill(int kill_result, int pid, char *msg)
{
	if (kill_result == -1)
	{
		kill(pid, SIGUSR2);
		if (msg)
			free(msg);
	}
	return ;
}

static char	*print_msg(char *msg)
{
	ft_putstr_fd(msg, 1);
	free(msg);
	return (NULL);
}

static void	bit_handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	s_c = 0b11111111;
	static int	s_bits = 0;
	static int	s_pid = 0;
	static char	*s_msg = 0;

	(void)ucontext;
	if (info->si_pid)
		s_pid = info->si_pid;
	if (sig == SIGUSR1)
		s_c ^= 0b10000000 >> s_bits;
	else if (sig == SIGUSR2)
		s_c |= 0b10000000 >> s_bits;
	if (++s_bits == 8)
	{
		if (s_c)
			s_msg = ft_joinchr(s_msg, s_c);
		else
			s_msg = print_msg(s_msg);
		s_bits = 0;
		s_c = 0b11111111;
	}
	check_kill(kill(s_pid, SIGUSR1), s_pid, s_msg);
}

int	main(void)
{
	int					pid;
	struct sigaction	bit;

	bit.sa_sigaction = &bit_handler;
	bit.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &bit, NULL);
	sigaction(SIGUSR2, &bit, NULL);
	pid = getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
