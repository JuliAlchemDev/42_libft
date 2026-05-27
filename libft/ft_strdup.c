/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iualkhim <iualkhim@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:32:28 by iualkhim          #+#    #+#             */
/*   Updated: 2026/05/21 12:28:51 by iualkhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	str_len;

	str_len = ft_strlen(s);
	dup = malloc(str_len + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, str_len + 1);
	return (dup);
}
