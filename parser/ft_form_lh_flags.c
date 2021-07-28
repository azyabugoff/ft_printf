/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_lh_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:54:08 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/11 00:11:45 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char				*ft_form_lh_flags(char *ptr, t_str *strct)
{
	if (*ptr == 'l' && *(ptr + 1) != 'l')
	{
		strct->lh_flags |= F_L;
		++ptr;
	}
	if (*ptr == 'l' && *(ptr + 1) == 'l')
	{
		strct->lh_flags |= F_LL;
		ptr = ptr + 2;
	}
	if (*ptr == 'h' && *(ptr + 1) != 'h')
	{
		strct->lh_flags |= F_H;
		++ptr;
	}
	if (*ptr == 'h' && *(ptr + 1) == 'h')
	{
		strct->lh_flags |= F_HH;
		ptr = ptr + 2;
	}
	return (ptr);
}
