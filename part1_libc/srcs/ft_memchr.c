#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
  size_t i;
  unsigned char *str;
  unsigned char chr;
  
  str = (unsigned char *)s;
  chr = (unsigned char)c;
  i = 0;
  while(i < n)
  {
    if(str[i] == chr)
        return (void *)(str + i);
    i++;
  }
    return (NULL);
}

