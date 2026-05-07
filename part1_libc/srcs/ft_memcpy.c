#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n){
    unsigned char *d;
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