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

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_printf("Wrong number of arguements\n\
The program should be executed as follows;\n./minitalk_client [PID NUMBER] [MESSAGE]\n");
    return (0);
    }
    if (is_pid_digit(argv[1]) == FALSE)
    {
        ft_printf("PID Number provided is not even a number.\n");
        return (0);
    }
    ft_printf("name of program:%s \n", argv[0]);
    return (0);
}