/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_before_percent.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:09:22 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/16 21:37:44 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char		*ft_print_before_percent(char *ptr, t_str *strct)
{
	while (*ptr && *ptr != '%')
	{
		ft_putchar_fd(*ptr, 1);
		++(strct->print_len);
		++ptr;
	}
	return (ptr);
}
