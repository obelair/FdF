/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:51:33 by obelair           #+#    #+#             */
/*   Updated: 2021/06/06 22:15:07 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

float	ft_scalar(t_vector u, t_vector v)
{
	float	scal;

	scal = u.x * v.x + u.y * v.y + u.z * v.z;
	return (scal);
}
