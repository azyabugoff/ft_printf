/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 02:55:42 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/19 01:33:49 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	ft_width_prec_1(t_str *strct, char *s, int diff, int s_len)
{
	if (strct->precision >= s_len)
		strct->precision = s_len;
	diff = (strct->width > strct->precision) ? strct->width - strct->precision
											: 0;
	strct->print_len += diff + strct->precision;
	if (strct->flags & F_MINUS)
	{
		while ((strct->precision--) > 0)
		{
			ft_putchar_fd(*s, 1);
			++s;
		}
		while ((diff--) > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while ((diff--) > 0)
			ft_putchar_fd(' ', 1);
		while ((strct->precision--) > 0)
		{
			ft_putchar_fd(*s, 1);
			++s;
		}
	}
}

static void	ft_width_prec_2(t_str *strct, char *s, int diff, int s_len)
{
	diff = strct->width - s_len;
	strct->print_len += diff + s_len;
	if (strct->flags & F_MINUS)
	{
		ft_putstr_fd(s, 1);
		while ((diff--) > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while ((diff--) > 0)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(s, 1);
	}
}

void		ft_string_handle(va_list *args, t_str *strct, char *nulll)
{
	char	*s;
	int		s_len;
	int		diff;

	diff = 0;
	s = va_arg(*args, char *);
	if (!s)
		s = nulll;
	s_len = ft_strlen(s);
	if (strct->width <= s_len && strct->precision < 0)
	{
		strct->print_len += s_len;
		ft_putstr_fd(s, 1);
	}
	else if (strct->width > s_len || strct->precision >= 0)
	{
		if (strct->precision >= 0 && strct->width > strct->precision)
			ft_width_prec_1(strct, s, diff, s_len);
		else if (strct->precision >= 0 && strct->width <= strct->precision)
			ft_width_prec_1(strct, s, diff, s_len);
		else if (strct->precision < 0 && strct->width > s_len)
			ft_width_prec_2(strct, s, diff, s_len);
	}
}
