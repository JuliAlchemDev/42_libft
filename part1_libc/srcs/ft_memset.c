/*
NAME
    memset – fill a byte string with a byte value
    void *memset(void *b, int c, size_t len);
DESCRIPTION
     The memset() function writes len bytes of value c
     (converted to an unsigned char) to the string b.

RETURN VALUES
    The memset() function returns its first argument.
*/
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