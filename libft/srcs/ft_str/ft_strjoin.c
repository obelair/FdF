/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:06:43 by obelair           #+#    #+#             */
/*   Updated: 2021/06/06 14:01:23 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	lens1;
	char	*cat;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	lens1 = ft_strlen(s1);
	cat = ft_calloc(lens1 + ft_strlen(s2) + 1, sizeof(char));
	if (!cat)
		return (NULL);
	while (s1 && s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		cat[i + j] = s2[j];
		j++;
	}
	cat[i + j] = 0;
	free(s1);
	return (cat);
}
