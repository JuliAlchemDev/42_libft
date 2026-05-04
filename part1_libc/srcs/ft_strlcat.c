/*

NAME
     strlcpy, strlcat – size-bounded string
     copying and concatenation

     size_t
     strlcat(char * restrict dst,
         const char * restrict src,
         size_t dstsize);
DESCRIPTION
     strlcat() appends string src to the end of
     dst.  It will append at most dstsize -
     strlen(dst) - 1 characters.  It will then
     NUL-terminate, unless dstsize is 0 or the
     original dst string was longer than dstsize
     (in practice this should not happen as it
     means that either dstsize is incorrect or
     that dst is not a proper string).

     If the src and dst strings overlap, the
     behavior is undefined.

RETURN VALUES     
     functions return the total length of the
     string they tried to create. 
*/
#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    if (dstsize == 0)
        return ft_strlen(src);
    size_t dst_len = ft_strlen(dst);
    size_t src_len = ft_strlen(src);
    size_t new_str_len = dst_len + src_len;
    size_t i;
    i = 0;
    if (dstsize > dst_len)
    {
        while (src[i] && dst_len + i < dstsize - 1)
        {
            dst[dst_len+i] = src[i];
            i++;
        }
        dst[dst_len + i] ='\0';
    }
    return new_str_len;
}