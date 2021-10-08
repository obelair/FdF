/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:28:10 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(n[i]))
		return ((char *)h);
	while (i < len && h[i])
	{
		j = 0;
		if (h[i] == n[j])
			while (h[i + j] == n[j] && i + j < len && h[i + j] && n[j])
				j++;
		if (!(n[j]))
			return ((char *)&h[i]);
		i++;
	}
	return (0);
}
