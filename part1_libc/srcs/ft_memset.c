#include "libft.h"

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