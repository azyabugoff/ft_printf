/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:54:54 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/19 02:32:16 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	ft_len_ptr(unsigned long ptr, t_str *strct)
{
	int		len;

	len = 0;
	if (ptr == 0)
	{
		len = 3;
		if (strct->dot == 1)
		{
			len = 2;
			return (len);
		}
	}
	else
	{
		while (ptr)
		{
			ptr /= 16;
			++len;
		}
		len += 2;
	}
	return (len);
}

static void	ft_putptr(unsigned long ptr, char *base, t_str *strct)
{
	char			arr[100];
	int				i;

	ft_putstr_fd("0x", 1);
	i = 0;
	if (ptr == 0)
	{
		if (strct->dot == 1)
			return ;
		ft_putchar_fd('0', 1);
	}
	else
	{
		while (ptr)
		{
			arr[i] = base[ptr % 16];
			ptr /= 16;
			++i;
		}
		while (--i >= 0)
			ft_putchar_fd(arr[i], 1);
	}
}

static void	ft_p_width(t_str *strct, unsigned long ptr, int diff)
{
	if (strct->flags & F_MINUS)
	{
		ft_putptr(ptr, "0123456789abcdef", strct);
		while ((diff--) > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while ((diff--) > 0)
			ft_putchar_fd(' ', 1);
		ft_putptr(ptr, "0123456789abcdef", strct);
	}
}

void		ft_pointer_handle(va_list *args, t_str *strct)
{
	int				len;
	unsigned long	ptr;
	int				diff;

	ptr = (unsigned long)va_arg(*args, void *);
	if (!ptr)
		ptr = 0;
	len = ft_len_ptr(ptr, strct);
	diff = strct->width - len;
	strct->print_len += (strct->width > len) ? (diff + len) : len;
	if (strct->width <= len)
		ft_putptr(ptr, "0123456789abcdef", strct);
	else
		ft_p_width(strct, ptr, diff);
}
