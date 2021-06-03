/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:43:11 by obelair           #+#    #+#             */
/*   Updated: 2021/06/03 10:43:33 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_word_join(char **s1, char *s2)
{
	char	**cat;
	int		i;

	if (!s1 && !s2)
		return (0);
	i = (int)ft_nbr_word(s1);
	cat = ft_calloc(i + 2, sizeof(char *));
	if (!cat)
		return (0);
	cat = ft_memcpy(cat, s1, i * sizeof(char *));
	cat[i] = ft_strdup(s2);
	free(s1);
	return (cat);
}
