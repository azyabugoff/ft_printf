/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:54:54 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/18 22:58:40 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void			ft_x_low_up_handle(va_list *args, t_str *strct, char c)
{
	if (c == 'x')
		ft_x_low_handle(args, strct);
	else if (c == 'X')
		ft_x_up_handle(args, strct);
}

void				ft_handle_args(va_list *args, t_str *strct)
{
	char	c;

	c = strct->type;
	if (c == 'c')
		ft_char_handle(args, strct);
	else if (c == 's')
		ft_string_handle(args, strct, "(null)");
	else if (c == 'p')
		ft_pointer_handle(args, strct);
	else if (c == 'd' || c == 'i')
		ft_int_handle(args, strct);
	else if (c == 'u')
		ft_uns_handle(args, strct);
	else if (c == 'x' || c == 'X')
		ft_x_low_up_handle(args, strct, c);
	else if (c == 'n')
		;
	else if (c == 'f')
		;
	else if (c == 'g')
		;
	else if (c == 'e')
		;
	else if (c == '%')
		ft_t_precent_handle(strct);
}
