/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iualkhim <iualkhim@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:31:29 by iualkhim          #+#    #+#             */
/*   Updated: 2026/05/21 14:50:12 by iualkhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len += 1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	len = ft_countlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i += 1;
	}
	while (len > i)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}
