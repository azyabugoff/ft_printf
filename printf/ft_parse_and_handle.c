/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_and_handle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:23:31 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/18 21:20:41 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_parse_and_handle(const char *format, va_list *args, t_str *strct)
{
	char	*ptr;

	ptr = (char *)format;
	while (*ptr)
	{
		ptr = ft_parser(ptr, args, strct);
		ft_handle_args(args, strct);
		ft_default_init_strct(strct);
	}
}
