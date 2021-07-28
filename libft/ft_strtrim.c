/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:01:04 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/11/08 18:56:47 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	s1_len;

	if (!s1)
		return (NULL);
	str = NULL;
	if (!set)
	{
		if (!(str = ft_strjoin((const char *)str, s1)))
			return (NULL);
		return (str);
	}
	while (*s1 && ft_strchr(set, *s1))
		++s1;
	s1_len = ft_strlen(s1);
	while (s1_len && ft_strchr(set, s1[s1_len]))
		--s1_len;
	if (!(str = ft_substr((char *)s1, 0, s1_len + 1)))
		return (NULL);
	return (str);
}
