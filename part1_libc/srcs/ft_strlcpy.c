/*
NAME
     strlcpy, strlcat – size-bounded string
     copying and concatenation
     size_t strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);

DESCRIPTION
     strlcpy() copies up to dstsize - 1 characters
     from the string src to dst, NUL-terminating
     the result if dstsize is not 0.
*/

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;

    i = 0;
    if(dstsize > 0)
    {
        while (i < dstsize - 1 && src[i])
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return ft_strlen(src);
}