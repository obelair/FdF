/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 23:36:00 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	cpy = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s1, ft_strlen(s1) + 1);
	return (cpy);
}
