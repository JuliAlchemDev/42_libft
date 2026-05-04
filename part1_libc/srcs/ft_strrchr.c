/*
NAME
    char *
     strrchr(const char *s, int c);

DESCRIPTION
     The strrchr() function is identical to
     strchr() except it locates the last
     occurrence of c.

RETURN VALUES
    The functions strchr() and strrchr()
     return a pointer to the located character,
     or NULL if the character does not appear
     in the string.
*/
#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
    int i;
    i = ft_strlen(str);
    while (i >= 0)
    {
        if (str[i] == (char)c)
            return (char *)&str[i];
        i--;
    }
    return (NULL);
}