#include <minitalk.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_printf("GTFO of here\n");
        // TODO error handle here
    }
    
    ft_printf("name of program:%s \n", argv[0]);
    return (0);
}