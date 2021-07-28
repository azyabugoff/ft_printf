/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:57:04 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/26 22:15:21 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int					ft_istype(char c)
{
	return (c == 'c' || c == 's' || c == 'p'
			|| c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == '%'
			|| c == 'X' || c == 'n' || c == 'f' || c == 'g' || c == 'e');
}

char				*ft_form_type(char *ptr, t_str *strct)
{
	if (ft_istype(*ptr))
	{
		strct->type = *ptr;
		++ptr;
	}
	return (ptr);
}
