#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
    {
        write(fd, "-2147483648", ft_strlen("-2147483648"));
        return ;
    }
    
    if (n < 0)
    {
        write(fd, "-", 1);
        n *= -1;
    }
    if (n >= 10)
    {
        ft_putnbr_fd(n / 10, fd);
    }
    
    char c = (n  % 10) + '0';
    write(fd, &c, 1);
}

/*
// LONG INT VERSION

void ft_putnbr_fd(int n, int fd)
{
    long int lg;
    
    lg = n;
    if (lg < 0)
    {
        write(fd, "-", 1);
        lg *= -1;
    }
    if (lg >= 10)
    {
        ft_putnbr_fd((int)(lg / 10), fd);
    }
    
    char c = (lg  % 10) + '0';
    write(fd, &c, 1);
}
    
*/
