/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:09:49 by obelair           #+#    #+#             */
/*   Updated: 2021/09/16 16:12:19 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_all_file *taf, int x, int y, int color)
{
	void	*dst;

	// printf("x : %d / y : %d\n", x, y);
	// printf("len : %d\n", taf->data.line_length);
	dst = taf->data.addr + (y * taf->data.line_length + x * 4);
	// printf("addr : %p | ind : %d | dst : %p | dst : %u | color : %d\n", taf->data.addr, (y * taf->data.line_length + x * 4), dst, *(unsigned int *)dst, color);
	*(unsigned int *)dst = color;
	// printf("Yo\n\n\n");
}

// void	draw_segment(t_vector a, t_vector b)
// {
// 	;
// }

int	next_frame(t_all_file *taf)
{
	int	i;
	int	j;

	i = 0;
	init_img(taf);
	while (i < (int)taf->data_pt.nbr_lines)
	{
		j = 0;
		while (j < (int)taf->data_pt.nbr_columns[i])
		{
			// printf("x : %d / y : %d\n", (int)(taf->data_pt.point[i][j].x * 10 + 10), (int)((taf->data_pt.point[i][j].y * 10) - taf->data_pt.point[i][j].z + 10));
			if ((taf->data_pt.point[i][j].y * 50) - taf->data_pt.point[i][j].z + 10 >= 0)
				my_mlx_pixel_put(taf, taf->data_pt.point[i][j].x * 50 + 10, (taf->data_pt.point[i][j].y * 50) - taf->data_pt.point[i][j].z + 10, taf->data_pt.color[i][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(taf->data.mlx, taf->data.win, taf->data.img, 0, 0);
	mlx_destroy_image(taf->data.mlx, taf->data.img);
	return (0);
}