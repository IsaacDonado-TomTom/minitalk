/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk_server.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 16:46:02 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/31 20:46:39 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

t_sig_data  g_sig_data;
void    init_struct();

void    zero_handler(int sig, siginfo_t *info, void *ucontext)
{
    (void)sig;
    (void)ucontext;
    (void)info;
    ft_printf("0");
    g_sig_data.index++;
    return ;
}

void    one_handler(int sig, siginfo_t *info, void *ucontext)
{
    (void)sig;
    (void)ucontext;
    (void)info;
    ft_printf("1");
    g_sig_data.index++;
    return ;
}

void    init_struct()
{
    g_sig_data.index = 0;
    return ;
}

void    receive_loop()
{
    while (1)
    {
        pause();
        if (g_sig_data.index == 8)
        {
            init_struct();
            ft_putchar_fd('\n', 1);
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
    init_struct();
    ft_putstr_fd("Server PID: ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    receive_loop();
    return (0);
}