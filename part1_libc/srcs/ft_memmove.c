/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iualkhim <iualkhim@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:51:59 by iualkhim          #+#    #+#             */
/*   Updated: 2026/05/04 14:02:32 by iualkhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     memmove – copy byte string

     void *memmove(void *dst, const void *src, size_t len);

DESCRIPTION
     The memmove() function copies len bytes from
     string src to string dst.  The two strings
     may overlap; the copy is always done in a
     non-destructive manner.

RETURN VALUES
     The memmove() function returns the original
     value of dst.
*/

#include "libft.h"

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
