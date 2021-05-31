/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:43:43 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*strdst;
	unsigned char	*strsrc;

	if (!dst && !src)
		return (0);
	strdst = (unsigned char *)dst;
	strsrc = (unsigned char *)src;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			strdst[i] = strsrc[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (0 < i--)
			strdst[i] = strsrc[i];
	}
	return (dst);
}
