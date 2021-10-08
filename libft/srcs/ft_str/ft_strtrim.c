/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:12:28 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trimend(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (set[i])
	{
		if (s1[j] == set[i])
		{
			j--;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

static int	ft_trimstart(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[i])
	{
		if (s1[j] == set[i])
		{
			j++;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	int		trimlen;
	int		i;

	if (!s1 || !set)
		return (NULL);
	if ((size_t)ft_trimstart(s1, set) == ft_strlen(s1))
		return (ft_strdup(""));
	trimlen = ft_trimend(s1, set) - ft_trimstart(s1, set) + 1;
	trim = malloc(sizeof(char) * (trimlen + 1));
	if (!trim)
		return (NULL);
	i = 0;
	while (i < trimlen)
	{
		trim[i] = s1[ft_trimstart(s1, set) + i];
		i++;
	}
	trim[i] = 0;
	return (trim);
}
