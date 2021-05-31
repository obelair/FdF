/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:09:08 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*strdst;
	unsigned char	*strsrc;

	i = 0;
	strdst = (unsigned char *)dst;
	strsrc = (unsigned char *)src;
	while (i < n)
	{
		strdst[i] = strsrc[i];
		if (strsrc[i] == (unsigned char)c)
			return (&strdst[i + 1]);
		i++;
	}
	return (0);
}
