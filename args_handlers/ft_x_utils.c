/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:13:11 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/26 22:17:40 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				ft_precision_diff_x(t_str *strct, int dig_rank)
{
	int		prec_diff;

	prec_diff = 0;
	if (strct->precision > dig_rank)
		prec_diff = strct->precision - dig_rank;
	return (prec_diff);
}

int				ft_len_x(unsigned int num)
{
	int		len;

	len = (!num) ? 1 : 0;
	while (num)
	{
		num /= 16;
		++len;
	}
	return (len);
}

void			ft_putnbr_x(unsigned int num, char *base)
{
	char			arr[100];
	int				i;

	i = 0;
	if (num == 0)
		write(1, "0", 1);
	else
	{
		while (num)
		{
			arr[i] = base[num % 16];
			num /= 16;
			++i;
		}
		while (--i >= 0)
			ft_putchar_fd(arr[i], 1);
	}
}
