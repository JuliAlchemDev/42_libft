/*
NAME
    memcpy – copy memory area
DESCRIPTION
     The memcpy() function copies n bytes from
     memory area src to memory area dst.  If dst
     and src overlap, behavior is undefined.
     Applications in which dst and src might
     overlap should use memmove(3) instead.

RETURN VALUES
     The memcpy() function returns the original
     value of dst.
*/

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n){
    char *d;
    const char *s;
    size_t i;
    
    d = dst;
    s = src;
    i = 0;

    while(i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dst);
}