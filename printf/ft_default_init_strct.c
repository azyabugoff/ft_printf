/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_init_strct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 01:04:19 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/16 19:10:19 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_default_init_strct(t_str *strct)
{
	strct->flags = NO_FLAGS;
	strct->width = 0;
	strct->dot = 0;
	strct->precision = -1;
	strct->lh_flags = NO_FLAGS;
	strct->type = ' ';
}
