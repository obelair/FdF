/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:50:28 by obelair           #+#    #+#             */
/*   Updated: 2021/06/06 18:50:49 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	ft_mult_vector(t_vector u, float k)
{
	t_vector	result;

	result.x = u.x * k;
	result.y = u.y * k;
	result.z = u.z * k;
	return (result);
}
