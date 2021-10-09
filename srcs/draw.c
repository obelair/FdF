/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:09:49 by obelair           #+#    #+#             */
/*   Updated: 2021/10/09 15:04:22 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_all_file *taf, int x, int y, int color)
{
	void	*dst;

	dst = taf->data.addr + (y * taf->data.line_length + x * 4);
	*(unsigned int *)dst = color;
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
	calc_pixel(taf);
	init_img(taf);
	while (i < taf->tdp.nbr_lines)
	{
		j = 0;
		while (j < taf->tdp.nbr_columns[i])
		{
			if (i < taf->tdp.nbr_lines - 1)
				draw_segment(taf, taf->tdp.pixel[i][j],
					taf->tdp.pixel[i + 1][j], taf->tdp.color[i][j]);
			if (j < taf->tdp.nbr_columns[i] - 1)
				draw_segment(taf, taf->tdp.pixel[i][j],
					taf->tdp.pixel[i][j + 1], taf->tdp.color[i][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(taf->data.mlx, taf->data.win, taf->data.img, 0, 0);
	mlx_destroy_image(taf->data.mlx, taf->data.img);
	return (0);
}
