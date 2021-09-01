#include <unistd.h>
#include <minitalk.h>

void    check_kill(int kill_return)
{
    if (kill_return >= 0)
        return ;
    else
    {
        ft_putstr_fd("\033[1m\033[31mError sending message!\033[1m\033[39m\n", 1);
        exit (errno);
    }
}

int is_pid_digit(char *pid)
{
    int i;

    i = 0;
    while (pid[i] != '\0')
    {
        if (ft_isdigit(pid[i]) == FALSE)
            return (0);
        i++;
    }
    return (1);
}

void    send_msg_subloop(int pid, char c)
{
    unsigned char byte;

    byte = 0b10000000;
    while (byte)
    {
        if ((byte&c) > 0)
            check_kill(kill(pid, SIGUSR2));
        else
            check_kill(kill(pid, SIGUSR1));
        byte = byte>>1;
        usleep(150);
    }
    return ;
}

void    send_msg_loop(int pid, char *msg)
{
    int i;

    i = 0;
    while (msg[i] != '\0')
    {
        send_msg_subloop(pid, msg[i]);
        i++;
    }
    send_msg_subloop(pid, msg[i]);
    return ;
}

void    success(int sig, siginfo_t *info, void *ucontext)
{
    (void)sig;
    (void)ucontext;
    (void)info;
    
    ft_putstr_fd("\033[1m\033[32mMessage sent!\033[1m\033[39m\n", 1);
    return ;
}

int main(int argc, char **argv)
{
    int pid;
    //struct sigaction    success;
    //struct sigaction    fail;

    //success.sa_sigaction = &success;
    //sigaction(SIGUSR1, &success, NULL);

    if (argc != 3)
    {
        ft_printf("Wrong number of arguements\n");
        ft_printf("The program should be executed as follows;\n");
        ft_printf("./minitalk_client [PID NUMBER] [MESSAGE]\n");
        return (0);
    }
    if (is_pid_digit(argv[1]) == FALSE)
    {
        ft_printf("PID Number provided is not even a number.\n");
        return (0);
    }
    pid = ft_atoi(argv[1]);
    if (kill(pid, 0) == ERROR)
    {
        ft_printf("Invalid process ID #%d \n", pid);
        return (0);
    }
    else
        send_msg_loop(pid, argv[2]);
    return (0);
}
