/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:58:42 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/26 22:15:27 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char		*ft_read_percent(char *ptr, va_list *args, t_str *strct)
{
	if (*ptr == '%')
	{
		++ptr;
		ptr = ft_form_flags(ptr, strct);
		ptr = ft_form_width(ptr, args, strct);
		ptr = ft_form_precision(ptr, args, strct);
		ptr = ft_form_lh_flags(ptr, strct);
		ptr = ft_form_type(ptr, strct);
		return (ptr);
	}
	else
		return (ptr);
}
