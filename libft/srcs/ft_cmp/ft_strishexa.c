/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strishexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:19:30 by obelair           #+#    #+#             */
/*   Updated: 2021/06/22 10:26:21 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strishexa(char *str, int suffixe)
{
	int	i;

	i = 0;
	if (suffixe)
	{
		if (!str || str[0] != '0' || !ft_strchr("Xx", str[1]))
			return (-1);
		i = 2;
	}
	while (str && str[i] && ft_strchr("0123456789abcdefABCDEF", str[i]))
		i++;
	if (!str || str[i])
		return (-1);
	return (0);
}
