/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:01:39 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/25 00:08:51 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static char	*check_prec_star(char *ptr, va_list *args, t_str *strct, int *tmp)
{
	if (*ptr == '*')
	{
		*tmp = va_arg(*args, int);
		if (*tmp < 0)
		{
			strct->dot = 0;
			strct->precision = -1;
			++ptr;
		}
		if (*tmp >= 0)
		{
			strct->precision = *tmp;
			++ptr;
		}
	}
	return (ptr);
}

char		*ft_form_precision(char *ptr, va_list *args, t_str *strct)
{
	int		tmp;

	tmp = 0;
	if (*ptr == '.')
	{
		strct->dot = 1;
		strct->precision = 0;
		++ptr;
		if (*ptr >= '0' && *ptr <= '9')
		{
			while (*ptr >= '0' && *ptr <= '9')
			{
				strct->precision *= 10;
				strct->precision += *ptr - '0';
				++ptr;
			}
		}
		ptr = check_prec_star(ptr, args, strct, &tmp);
	}
	return (ptr);
}
