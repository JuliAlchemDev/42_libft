/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iualkhim <iualkhim@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:34:01 by iualkhim          #+#    #+#             */
/*   Updated: 2026/05/21 15:43:13 by iualkhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (s[start] && ft_strchr(set, s[start]))
		start++;
	while (end > start && ft_strrchr(set, s[end - 1]))
		end--;
	return (ft_substr(s, start, end - start));
}
