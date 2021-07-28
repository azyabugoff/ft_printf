/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:01:39 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/17 02:31:52 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static char	*check_width_star(char *ptr, va_list *args, t_str *strct, int *tmp)
{
	if (*ptr == '*')
	{
		*tmp = va_arg(*args, int);
		if (*tmp >= 0)
		{
			strct->width = *tmp;
			++ptr;
		}
		else
		{
			strct->width = -(*tmp);
			if (!(strct->flags & F_MINUS))
			{
				if (strct->flags & F_ZERO)
					strct->flags &= (~F_ZERO);
				strct->flags |= F_MINUS;
			}
			++ptr;
		}
	}
	return (ptr);
}

char		*ft_form_width(char *ptr, va_list *args, t_str *strct)
{
	int		tmp;

	while (*ptr >= '0' && *ptr <= '9')
	{
		strct->width *= 10;
		strct->width += *ptr - '0';
		++ptr;
	}
	tmp = 0;
	ptr = check_width_star(ptr, args, strct, &tmp);
	return (ptr);
}
