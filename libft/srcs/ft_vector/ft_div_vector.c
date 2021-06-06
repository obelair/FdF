/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:38:09 by obelair           #+#    #+#             */
/*   Updated: 2021/06/06 18:52:01 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	ft_div_vector(t_vector u, float k)
{
	t_vector	result;

	if (k)
	{
		result.x = u.x / k;
		result.y = u.y / k;
		result.z = u.z / k;
	}
	else
	{
		result.x = 0;
		result.y = 0;
		result.z = 0;
	}
	return (result);
}
