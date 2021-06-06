/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:50:30 by obelair           #+#    #+#             */
/*   Updated: 2021/06/06 13:48:11 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intjoin(int *n1, const int *n2, size_t len_n1, size_t len_n2)
{
	int		*cat;
	size_t	i;

	if (!n1 && !n2)
		return (NULL);
	cat = ft_calloc(len_n1 + len_n2, sizeof(int));
	if (!cat)
		return (NULL);
	i = 0;
	while (i < len_n1)
	{
		cat[i] = n1[i];
		i++;
	}
	while (i < len_n1 + len_n2)
	{
		cat[i] = n2[i - len_n1];
		i++;
	}
	free(n1);
	return (cat);
}
