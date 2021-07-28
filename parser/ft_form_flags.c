/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:54:08 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/17 23:05:59 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int		is_flag(char c)
{
	return (c == '#' || c == '-' || c == '+'
			|| c == ' ' || c == '0');
}

static void		check_flag_minus(char *ptr, t_str *strct)
{
	if (*ptr == '-' && !(strct->flags & F_MINUS))
	{
		if (strct->flags & F_ZERO)
			strct->flags &= (~F_ZERO);
		strct->flags |= F_MINUS;
	}
}

static void		check_flag_plus(char *ptr, t_str *strct)
{
	if (*ptr == '+' && !(strct->flags & F_PLUS))
	{
		if (strct->flags & F_SPACE)
			strct->flags &= (~F_SPACE);
		strct->flags |= F_PLUS;
	}
}

char			*ft_form_flags(char *ptr, t_str *strct)
{
	while (is_flag(*ptr))
	{
		if (*ptr == '#' && !(strct->flags & F_OCTOTROP))
			strct->flags |= F_OCTOTROP;
		check_flag_minus(ptr, strct);
		if (*ptr == '0' && !(strct->flags & F_MINUS)
						&& !(strct->flags & F_ZERO))
			strct->flags |= F_ZERO;
		check_flag_plus(ptr, strct);
		if (*ptr == ' ' && !(strct->flags & F_PLUS)
						&& !(strct->flags & F_SPACE))
			strct->flags |= F_SPACE;
		++ptr;
	}
	return (ptr);
}
