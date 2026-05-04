/*
NAME
    bzero – write zeroes ('\0') to a byte string
    void bzero(void *s, size_t n);
DESCRIPTION & RETURN VALUES
     The bzero() function writes n zeroed bytes to
     the string s.  If n is zero, bzero() does
     nothing.

*/
#include "libft.h"

void ft_bzero(void *str, size_t n)
{
    ft_memset(str, 0, n);
}
