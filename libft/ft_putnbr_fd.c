/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iualkhim <iualkhim@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 12:51:42 by iualkhim          #+#    #+#             */
/*   Updated: 2026/05/21 13:06:05 by iualkhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	lg;
	char		c;

	lg = n;
	if (lg < 0)
	{
		write(fd, "-", 1);
		lg *= -1;
	}
	if (lg >= 10)
	{
		ft_putnbr_fd((int)(lg / 10), fd);
	}
	c = (lg % 10) + '0';
	ft_putchar_fd(c, fd);
}
