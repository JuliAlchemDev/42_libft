/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iualkhim <iualkhim@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:41:23 by iualkhim          #+#    #+#             */
/*   Updated: 2026/05/21 14:10:39 by iualkhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	join = malloc(len_s1 + len_s2 + 1);
	if (!join)
		return (NULL);
	ft_memcpy(join, s1, len_s1);
	ft_memcpy(join + len_s1, s2, len_s2);
	join[len_s1 + len_s2] = '\0';
	return (join);
}
