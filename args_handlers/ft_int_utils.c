/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:13:11 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/18 19:08:41 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				ft_dig_rank(long int num)
{
	int		dig_rank;

	dig_rank = (num < 0) ? 2 : 1;
	while ((num /= 10) != 0)
		++dig_rank;
	return (dig_rank);
}

int				ft_precision_diff(t_str *strct, long int num, int dig_rank)
{
	int		prec_diff;

	prec_diff = 0;
	if (num < 0)
		--dig_rank;
	if (strct->precision > dig_rank)
		prec_diff = strct->precision - dig_rank;
	return (prec_diff);
}
