/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:46:13 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/16 16:28:42 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_parser(char *ptr, va_list *args, t_str *strct)
{
	ptr = ft_print_before_percent(ptr, strct);
	ptr = ft_read_percent(ptr, args, strct);
	return (ptr);
}
