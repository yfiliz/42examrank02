#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int res = 0;

    while(str[i] == ' ' && str[i] == '\t')
        i++;
    if(str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if(str[i] == '+')
        i++;
    while(str[i] && str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + (str[i] - '0');
        i++;
    }
    return(res * sign);
}

void ft_printhex(unsigned int nb)
{
    const char base[] = "0123456789abcdef";

    if(nb > 16)
    {
        ft_printhex(nb/16);
        ft_printhex(nb%16);
    }
    else
        write(1, &base[nb%16], 1);
}

int main(int ac, char **av)
{
    int res = 0;
    int nb;

    if(ac == 2)
    {
        nb = ft_atoi(av[1]);
        if(nb >= 0)
        {
            ft_printhex(nb);
        }
    }
    write(1, "\n", 1);
    return(0);
}