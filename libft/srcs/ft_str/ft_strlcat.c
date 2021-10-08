/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:08:28 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstsize;

	i = 0;
	dstsize = ft_strlen(dst);
	if (dstsize >= size)
		return (ft_strlen(src) + size);
	while (i + dstsize < size - 1 && src[i])
	{
		dst[dstsize + i] = src[i];
		i++;
	}
	dst[i + dstsize] = 0;
	return (ft_strlen(src) + dstsize);
}
