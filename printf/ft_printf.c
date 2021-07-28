/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:01:34 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/24 21:10:42 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_str		strct;

	if (!format)
		return (-1);
	ft_default_init_strct(&strct);
	strct.print_len = 0;
	if (format)
	{
		va_start(args, format);
		ft_parse_and_handle(format, &args, &strct);
		va_end(args);
	}
	return (strct.print_len);
}
