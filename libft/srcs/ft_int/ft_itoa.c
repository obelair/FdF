/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 08:21:33 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*result;
	int			i;
	long int	nb;

	nb = n;
	if (nb < 0)
		i = ft_intblen(n, 10) + 1;
	else
		i = ft_intblen(n, 10);
	result = calloc(sizeof(char), (i + 1));
	if (!result)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		result[0] = '-';
	}
	else if (!nb)
		result[0] = '0';
	while (nb > 0)
	{
		result[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (result);
}
