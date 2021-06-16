/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:53:47 by obelair           #+#    #+#             */
/*   Updated: 2021/06/16 14:54:29 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && (str[i] == '-' || ft_isdigit(str[i])))
		i++;
	if (!str || (str[i] && str[i] != '-' && !ft_isdigit(str[i])))
		return (1);
	return (0);
}
