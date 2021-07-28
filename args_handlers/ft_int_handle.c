/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:13:11 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/19 02:12:03 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	ft_int_fminus(long int num, int diff, int prec_diff, t_str *strct)
{
	int		flag;

	flag = (num == MIN_INT) ? 1 : 0;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
	}
	while ((prec_diff--) > 0)
		ft_putchar_fd('0', 1);
	if (flag == 1)
	{
		ft_putnbr_fd(num / 10, 1);
		ft_putnbr_fd(num % 10, 1);
	}
	else
	{
		if (!(num == 0 && strct->precision == 0))
			ft_putnbr_fd(num, 1);
		else
			ft_putchar_fd(' ', 1);
	}
	while ((diff--) > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_int_fzero(long int num, int diff, t_str *strct)
{
	int		flag;

	flag = (num == MIN_INT) ? 1 : 0;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
	}
	while ((diff--) > 0)
		ft_putchar_fd('0', 1);
	if (flag == 1)
	{
		ft_putnbr_fd(num / 10, 1);
		ft_putnbr_fd(num % 10, 1);
	}
	else
	{
		if (!(num == 0 && strct->precision == 0))
			ft_putnbr_fd(num, 1);
		else
			ft_putchar_fd(' ', 1);
	}
}

static void	ft_int_fno(long int num, int diff, int prec_diff, t_str *strct)
{
	int		flag;

	flag = (num == MIN_INT) ? 1 : 0;
	while ((diff--) > 0)
		ft_putchar_fd(' ', 1);
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
	}
	while ((prec_diff--) > 0)
		ft_putchar_fd('0', 1);
	if (flag == 1)
	{
		ft_putnbr_fd(num / 10, 1);
		ft_putnbr_fd(num % 10, 1);
	}
	else
	{
		if (!(num == 0 && strct->precision == 0))
			ft_putnbr_fd(num, 1);
		else
			ft_putchar_fd(' ', 1);
	}
}

static void	ft_int_fminus_fzero_fno(t_str *strct, long int num,
									int dig_rank, int prec_diff)
{
	int			diff;

	diff = strct->width - dig_rank - prec_diff;
	strct->print_len += (diff > 0)
						? diff + dig_rank + prec_diff : dig_rank + prec_diff;
	if (strct->flags & F_MINUS)
		ft_int_fminus(num, diff, prec_diff, strct);
	else if ((strct->flags & F_ZERO) && (strct->dot == 0))
		ft_int_fzero(num, diff, strct);
	else
		ft_int_fno(num, diff, prec_diff, strct);
}

void		ft_int_handle(va_list *args, t_str *strct)
{
	long int		num;
	int				dig_rank;
	int				prec_diff;

	num = (long int)va_arg(*args, int);
	dig_rank = ft_dig_rank(num);
	prec_diff = ft_precision_diff(strct, num, dig_rank);
	if (strct->width <= dig_rank && prec_diff <= 0)
	{
		strct->print_len += dig_rank;
		if (num == 0 && strct->precision == 0)
		{
			strct->print_len -= (strct->width == 0) ? 1 : 0;
			while ((strct->width--) > 0)
				ft_putchar_fd(' ', 1);
		}
		else
			ft_putnbr_fd(num, 1);
	}
	else if (strct->width > dig_rank || prec_diff > 0)
		ft_int_fminus_fzero_fno(strct, num, dig_rank, prec_diff);
}
