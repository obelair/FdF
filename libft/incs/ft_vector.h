/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:47:46 by obelair           #+#    #+#             */
/*   Updated: 2021/06/06 22:21:00 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <string.h>
# include <math.h>

/*	===================
	===  ft_vector  ===
	===================	*/

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

t_vector	ft_add_vector(t_vector u, t_vector v);
t_vector	ft_minus_vector(t_vector u, t_vector v);
t_vector	ft_div_vector(t_vector u, float k);
t_vector	ft_mult_vector(t_vector u, float k);
float		ft_scalar(t_vector u, t_vector v);
t_vector	rot_x(t_vector u, double ang);
t_vector	rot_y(t_vector u, double ang);
t_vector	rot_z(t_vector u, double ang);

#endif
