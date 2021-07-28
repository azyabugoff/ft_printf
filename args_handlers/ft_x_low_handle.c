/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_low_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:54:54 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/26 22:18:23 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	ft_x_fminus(unsigned int num, int diff,
						int prec_diff, t_str *strct)
{
	while ((prec_diff--) > 0)
		ft_putchar_fd('0', 1);
	if (num == 0 && strct->precision == 0)
		ft_putchar_fd(' ', 1);
	else
		ft_putnbr_x(num, "0123456789abcdef");
	while ((diff--) > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_x_fzero(unsigned int num, int diff, t_str *strct)
{
	while ((diff--) > 0)
		ft_putchar_fd('0', 1);
	if (num == 0 && strct->precision == 0)
		ft_putchar_fd(' ', 1);
	else
		ft_putnbr_x(num, "0123456789abcdef");
}

static void	ft_x_fno(unsigned int num, int diff, int prec_diff, t_str *strct)
{
	while ((diff--) > 0)
		ft_putchar_fd(' ', 1);
	while ((prec_diff--) > 0)
		ft_putchar_fd('0', 1);
	if (num == 0 && strct->precision == 0)
		ft_putchar_fd(' ', 1);
	else
		ft_putnbr_x(num, "0123456789abcdef");
}

static void	ft_x_fminus_fzero_fno(t_str *strct, unsigned int num,
									int dig_rank, int prec_diff)
{
	int		diff;

	diff = strct->width - dig_rank - prec_diff;
	strct->print_len += (diff > 0) ? diff + dig_rank + prec_diff
									: dig_rank + prec_diff;
	if (strct->flags & F_MINUS)
		ft_x_fminus(num, diff, prec_diff, strct);
	else if ((strct->flags & F_ZERO) && (strct->dot == 0))
		ft_x_fzero(num, diff, strct);
	else
		ft_x_fno(num, diff, prec_diff, strct);
}

void		ft_x_low_handle(va_list *args, t_str *strct)
{
	unsigned int	num;
	int				dig_rank;
	int				prec_diff;

	num = (unsigned int)va_arg(*args, int);
	dig_rank = ft_len_x(num);
	prec_diff = ft_precision_diff_x(strct, dig_rank);
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
			ft_putnbr_x(num, "0123456789abcdef");
	}
	else
		ft_x_fminus_fzero_fno(strct, num, dig_rank, prec_diff);
}
