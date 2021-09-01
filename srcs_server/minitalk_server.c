/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk_server.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 16:46:02 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/01 00:02:51 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

t_sig_data  g_sig_data;

void    zero_handler(int sig, siginfo_t *info, void *ucontext)
{
    (void)sig;
    (void)ucontext;
    (void)info;
    g_sig_data.index++;
    return ;
}

void    one_handler(int sig, siginfo_t *info, void *ucontext)
{
    unsigned char byte;

    (void)sig;
    (void)ucontext;
    (void)info;

    byte = 0b10000000;
    g_sig_data.buffer[g_sig_data.str_index] |= byte >> g_sig_data.index;
    g_sig_data.index++;
    return ;
}

void    receive_loop()
{
    while (1)
    {
        pause();
        if (g_sig_data.index == 8)
        {
            ft_putchar_fd(g_sig_data.buffer[g_sig_data.str_index], 1);
            if (g_sig_data.buffer[g_sig_data.str_index] == '\0')
                ft_putchar_fd('\n', 1);
            g_sig_data.index = 0;
            g_sig_data.str_index++;
        }
    }
    return ;
}

int main(void)
{
    int pid;
    struct sigaction    zero;
    struct sigaction    one;

    zero.sa_sigaction = &zero_handler;
    sigaction(SIGUSR1, &zero, NULL);
    one.sa_sigaction = &one_handler;
    sigaction(SIGUSR2, &one, NULL);
    pid = getpid();
    g_sig_data.str_index = 0;
    g_sig_data.index = 0;
    ft_putstr_fd("Server PID: ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    receive_loop();
    return (0);
}