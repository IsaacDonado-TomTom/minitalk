#include <unistd.h>
#include <minitalk.h>

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

void    send_msg_loop(int pid, char *msg)
{
    int i;
    unsigned char byte;

    i = 0;
    while (msg[i] != '\0')
    {
        byte = 255;
        while (byte)
        {
            if ((byte & msg[i]) == 1)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            byte = byte >> 1;
            usleep(100);
        }
        i++;
    }
    byte = 0b10000000;
        while (byte)
    {
        if ((byte & msg[i]) == 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        byte = byte >> 1;
        usleep(1000);
    }
}

int main(int argc, char **argv)
{
    int pid;

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
