/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_dbl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:37:08 by obelair           #+#    #+#             */
/*   Updated: 2021/10/07 12:51:17 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_dbl(t_list **list, void **new, size_t size, int back)
{
	size_t	i;

	i = 0;
	if (ft_lstadd_void(list, new, back))
		return (-1);
	while (i < size)
	{
		if (ft_lstadd_void(list, new[i], back))
			return (-1);
		i++;
	}
	return (0);
}
