/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:13:11 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/26 22:19:05 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				ft_len_u(unsigned int num)
{
	int		len;

	len = (!num) ? 1 : 0;
	while (num)
	{
		num /= 10;
		++len;
	}
	return (len);
}

int				ft_precision_diff_u(t_str *strct, int dig_rank)
{
	int		prec_diff;

	prec_diff = 0;
	if (strct->precision > dig_rank)
		prec_diff = strct->precision - dig_rank;
	return (prec_diff);
}

void			ft_putnbr_u(unsigned int n)
{
	int			i;
	char		arr[12];

	i = 0;
	if (n == 0)
		write(1, "0", 1);
	else
	{
		while (n)
		{
			arr[i++] = n % 10 + '0';
			n /= 10;
		}
		while (i--)
			write(1, &arr[i], 1);
	}
}
