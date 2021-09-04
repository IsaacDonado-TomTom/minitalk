/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk_server.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 16:46:02 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/04 20:30:12 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

t_sig_data	g_sig_data;

static void	clear_global_struct(void)
{
	int	i;

	i = 0;
	g_sig_data.str_index = 0;
	g_sig_data.index = 0;
	g_sig_data.sender_pid = 0;
	return ;
}

static void	zero_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)ucontext;
	(void)info;
	g_sig_data.index++;
	if (!g_sig_data.sender_pid)
		g_sig_data.sender_pid = info->si_pid;
	return ;
}

static void	one_handler(int sig, siginfo_t *info, void *ucontext)
{
	unsigned char	byte;

	(void)sig;
	(void)ucontext;
	(void)info;
	byte = 0b10000000;
	g_sig_data.temp_char |= byte >> g_sig_data.index;
	g_sig_data.index++;
	if (!g_sig_data.sender_pid)
		g_sig_data.sender_pid = info->si_pid;
	return ;
}

static void	receive_loop(void)
{
	while (1)
	{
		pause();
		if (g_sig_data.index == CHAR_BITS)
		{
			g_sig_data.buffer = ft_joinchr(g_sig_data.buffer, \
			g_sig_data.temp_char, g_sig_data.str_index);
			g_sig_data.temp_char = 0;
			if (g_sig_data.buffer[g_sig_data.str_index] == '\0')
			{
				ft_putstr_fd(g_sig_data.buffer, 1);
				ft_putchar_fd('\n', 1);
				if (g_sig_data.buffer != NULL)
					free(g_sig_data.buffer);
				g_sig_data.buffer = NULL;
				check_kill(kill(g_sig_data.sender_pid, SIGUSR1));
				clear_global_struct();
				g_sig_data.str_index = -1;
			}
			g_sig_data.index = 0;
			g_sig_data.str_index++;
		}
	}
	return ;
}

int	main(void)
{
	int					pid;
	struct sigaction	zero;
	struct sigaction	one;

	zero.sa_sigaction = &zero_handler;
	zero.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &zero, NULL);
	one.sa_sigaction = &one_handler;
	one.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &one, NULL);
	pid = getpid();
	g_sig_data.buffer = NULL;
	clear_global_struct();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	receive_loop();
	return (0);
}
