/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 23:03:23 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/11/08 16:22:59 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*s;
	int		i;

	i = 0;
	size = ft_strlen(s1);
	if (!(s = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	else
	{
		while (s1[i])
		{
			s[i] = s1[i];
			++i;
		}
	}
	s[i] = '\0';
	return (s);
}
