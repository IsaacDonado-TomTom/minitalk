#include <signal.h>
#include <minitalk.h>

int main(void)
{
    ft_printf("PID: %d\n", getpid());
    while (1){};
    return (0);
}