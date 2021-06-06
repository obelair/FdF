/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:55:46 by obelair           #+#    #+#             */
/*   Updated: 2021/06/06 14:02:07 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (len > lens)
		len = lens - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	if (lens > (size_t)start)
	{
		while (i < len && s[start + i])
		{
			sub[i] = s[start + i];
			i++;
		}
	}
	sub[i] = 0;
	return (sub);
}
