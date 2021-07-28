/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 02:55:42 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/26 22:17:00 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_char_handle(va_list *args, t_str *strct)
{
	char	c;

	c = va_arg(*args, int);
	if (strct->width <= (int)sizeof(char))
	{
		strct->print_len += sizeof(char);
		ft_putchar_fd(c, 1);
	}
	else if (strct->width > (int)sizeof(char))
	{
		strct->print_len += strct->width;
		if (strct->flags & F_MINUS)
		{
			ft_putchar_fd(c, 1);
			while ((strct->width--) - sizeof(char) > 0)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while ((strct->width--) - sizeof(char) > 0)
				ft_putchar_fd(' ', 1);
			ft_putchar_fd(c, 1);
		}
	}
}

static void	ft_t_perc_width(t_str *strct)
{
	strct->print_len += strct->width;
	if (strct->flags & F_MINUS)
	{
		ft_putchar_fd('%', 1);
		while ((strct->width--) - sizeof(char) > 0)
			ft_putchar_fd(' ', 1);
	}
	else if (strct->flags & F_ZERO)
	{
		while ((strct->width--) - sizeof(char) > 0)
			ft_putchar_fd('0', 1);
		ft_putchar_fd('%', 1);
	}
	else
	{
		while ((strct->width--) - sizeof(char) > 0)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('%', 1);
	}
}

void		ft_t_precent_handle(t_str *strct)
{
	if (strct->width <= (int)sizeof(char))
	{
		strct->print_len += sizeof(char);
		ft_putchar_fd('%', 1);
	}
	else if (strct->width > (int)sizeof(char))
		ft_t_perc_width(strct);
}
