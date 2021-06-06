/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 22:17:37 by obelair           #+#    #+#             */
/*   Updated: 2021/06/06 22:19:28 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	rot_x(t_vector u, double ang)
{
	t_vector	v;

	v.x = u.x;
	v.y = u.y * cos(ang) + u.z * sin(ang);
	v.z = u.y * -1 * sin(ang) + u.z * cos(ang);
	return (v);
}

t_vector	rot_y(t_vector u, double ang)
{
	t_vector	v;

	v.x = u.x * cos(ang) + u.z * -1 * sin(ang);
	v.y = u.y;
	v.z = u.x * sin(ang) + u.z * cos(ang);
	return (v);
}

t_vector	rot_z(t_vector u, double ang)
{
	t_vector	v;

	v.x = u.x * cos(ang) + u.y * sin(ang);
	v.y = u.x * -1 * sin(ang) + u.y * cos(ang);
	v.z = u.z;
	return (v);
}
