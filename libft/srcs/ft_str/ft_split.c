/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 08:57:31 by obelair           #+#    #+#             */
/*   Updated: 2021/06/06 14:01:38 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbword(const char *s, char c)
{
	int	i;
	int	nb;

	i = -1;
	nb = 0;
	while (s[++i])
		if (s[i] && s[i] != c && (s[i + 1] == 0 || s[i + 1] == c))
			nb++;
	return (nb);
}

static	char	**ft_freeall(char **split, int i)
{
	while (0 <= --i)
		free(split[i]);
	free(split);
	return (NULL);
}

static int	strnchr(const char *str, char c, int beg)
{
	while (str[beg] && str[beg] == c)
		beg++;
	return (beg);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	int		i;
	int		beg;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_nbword(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	beg = 0;
	while (i < ft_nbword(s, c))
	{
		beg = strnchr(s, c, beg);
		if (s[beg] != c && s[beg])
		{
			split[i] = ft_substr(s, beg, ft_strichr(s + beg, c));
			if (!split[i])
				return (ft_freeall(split, i));
			beg += ft_strichr(s + beg, c) + 1;
			i++;
		}
	}
	split[i] = 0;
	return (split);
}
