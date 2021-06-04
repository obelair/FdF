/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:14:14 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:39:25 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	rot_x(t_vector ray, double ang)
{
	t_vector	new;

	new.x = ray.x;
	new.y = ray.y * cos(ang) + ray.z * sin(ang);
	new.z = ray.y * -1 * sin(ang) + ray.z * cos(ang);
	return (new);
}

t_vector	rot_y(t_vector ray, double ang)
{
	t_vector	new;

	new.x = ray.x * cos(ang) + ray.z * -1 * sin(ang);
	new.y = ray.y;
	new.z = ray.x * sin(ang) + ray.z * cos(ang);
	return (new);
}

t_vector	rot_z(t_vector ray, double ang)
{
	t_vector	new;

	new.x = ray.x * cos(ang) + ray.y * sin(ang);
	new.y = ray.x * -1 * sin(ang) + ray.y * cos(ang);
	new.z = ray.z;
	return (new);
}
