/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:09:49 by obelair           #+#    #+#             */
/*   Updated: 2021/06/22 17:17:39 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	next_frame(t_all_file *taf)
{
	// int	i;
	// int	j;

	// i = 0;
	// while (i < HEIGHT)
	// {
	// 	j = 0;
	// 	while (j < WIDTH)
	// 	{

	// 	}
	// }
	init_img(taf);
	mlx_put_image_to_window(taf->data.mlx, taf->data.win, taf->data.img, 0, 0);
	mlx_destroy_image(taf->data.mlx, taf->data.img);
	return (0);
}