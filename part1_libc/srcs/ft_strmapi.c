#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *copy;
    size_t len;
    size_t i;

    len = ft_strlen(s);
    copy = malloc(len + 1);
    if(!copy)
        return (NULL);
    i = 0;
    while(s[i])
    {
        copy[i] = f(i, s[i]);
        i++;
    }
    copy[i] = '\0';
    return (copy);
}