/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:09:49 by obelair           #+#    #+#             */
/*   Updated: 2021/10/08 16:04:52 by obelair          ###   ########lyon.fr   */
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

void	draw_segment(t_all_file *taf, t_pixel a, t_pixel b, int color)
{
	float	t;
	float	offset;
	t_pixel	ab;

	t = 0;
	ab.x = b.x - a.x;
	ab.y = b.y - a.y;
	offset = 1 / hypotf(ab.x, ab.y);
	while (t <= 1)
	{
		// printf("offset : %f | x : %f | y : %f\n", offset, ab.x * t + a.x, ab.y * t + a.y);
		if (0 <= ab.x * t + a.x && ab.x * t + a.x < WIDTH
			&& 0 <= ab.y * t + a.y && ab.y * t + a.y < HEIGHT)
			my_mlx_pixel_put(taf, ab.x * t + a.x, ab.y * t + a.y, color);
		t += offset;
	}
}

int	next_frame(t_all_file *taf)
{
	size_t	i;
	size_t	j;

	i = 0;
	// calc_pixel(taf);
	init_img(taf);
	while (i < taf->data_pt.nbr_lines)
	{
		j = 0;
		while (j < taf->data_pt.nbr_columns[i])
		{
			// printf("[%ld,%ld] : [%d,%d]\n", i, j, taf->data_pt.pixel[i][j].x, taf->data_pt.pixel[i][j].y);
			if (i < taf->data_pt.nbr_lines - 1)
				draw_segment(taf, taf->data_pt.pixel[i][j], taf->data_pt.pixel[i + 1][j], taf->data_pt.color[i][j]);
			if (j < taf->data_pt.nbr_columns[i] - 1)
				draw_segment(taf, taf->data_pt.pixel[i][j], taf->data_pt.pixel[i][j + 1], taf->data_pt.color[i][j]);
			// if (taf->data_pt.pixel[i][j].x >= 0 && taf->data_pt.pixel[i][j].y >= 0 && taf->data_pt.point[i][j].z)
			// 	my_mlx_pixel_put(taf, taf->data_pt.pixel[i][j].x, taf->data_pt.pixel[i][j].y, 0xFF0000);
			// else if (taf->data_pt.pixel[i][j].x >= 0 && taf->data_pt.pixel[i][j].y >= 0)
			// 	my_mlx_pixel_put(taf, taf->data_pt.pixel[i][j].x, taf->data_pt.pixel[i][j].y, taf->data_pt.color[i][j]);
			// if (i < taf->data_pt.nbr_lines - 1 && j < taf->data_pt.nbr_columns[i] - 1)
			// 	draw_segment(taf, taf->data_pt.pixel[i][j], taf->data_pt.pixel[i + 1][j + 1], taf->data_pt.color[i][j]);
			// my_mlx_pixel_put(taf, taf->data_pt.pixel[i][j].x, taf->data_pt.pixel[i][j].y, taf->data_pt.color[i][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(taf->data.mlx, taf->data.win, taf->data.img, 0, 0);
	mlx_destroy_image(taf->data.mlx, taf->data.img);
	// printf("****************************************\n");
	return (0);
}
