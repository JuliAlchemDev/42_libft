## Block 4 - Memory Manipulation
### Functions

void *ft_memset(void *str, int value, size_t len)
{
    char *str_of_value;
    size_t i;
    i = 0;
    
    str_of_value = str;
    while(i < len)
    {
        str_of_value[i] = (unsigned char)value;
        i++;
    }
    return (str);
}

void ft_bzero(void *str, size_t n)
{
    ft_memset(str, 0, n);
}

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

void *ft_memmove(void *dest, const void *src, size_t len)
{
    unsigned char       *d;
    const unsigned char *s;

    d = (unsigned char *)dest;
    s = (unsigned char *)src;

    if (d < s)                   
    {
        while (len--)
            *d++ = *s++;
    }
    else                          
    {
        d += len;
        s += len;
        while (len--)
            *--d = *--s;
    }
    return (dest);
}

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

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *str_1;
    unsigned char *str_2;
    size_t i;

    str_1 = (unsigned char *) s1;
    str_2 = (unsigned char *) s2;
    i =0;
    
    while(i < n)
    {
        if(str_1[i] != str_2[i])
            return (str_1[i] - str_2[i]); 
        i++;
    }
    return (0);
}