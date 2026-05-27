/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iualkhim <iualkhim@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:07:36 by iualkhim          #+#    #+#             */
/*   Updated: 2026/05/06 13:27:43 by iualkhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*cast;
	size_t	i;

	cast = (char *)s;
	i = 0;
	while (i < n)
	{
		cast[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
