/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_void.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:34:21 by obelair           #+#    #+#             */
/*   Updated: 2021/10/07 12:51:21 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_void(t_list **list, void *new, int back)
{
	if (back)
	{
		ft_lstadd_back(list, ft_lstnew(new));
		if (!*list)
			return (-1);
	}
	else
	{
		ft_lstadd_front(list, ft_lstnew(new));
		if (!*list)
			return (-1);
	}
	return (0);
}
