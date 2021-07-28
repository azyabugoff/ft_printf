/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:38:18 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/18 19:07:57 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			size;
	unsigned	cp;
	char		arr[12];

	size = 0;
	cp = (unsigned)((n >= 0) ? n : -n);
	if (cp == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
			write(fd, "-", 1);
		while (cp)
		{
			arr[size++] = cp % 10 + '0';
			cp /= 10;
		}
		while (size)
		{
			write(fd, &arr[--size], 1);
		}
	}
}
