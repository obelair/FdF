/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:47:28 by obelair           #+#    #+#             */
/*   Updated: 2021/10/09 19:26:10 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_scale(t_all_file *taf)
{
	float	scale_v;
	float	scale_h;

	scale_v = (float)WIDTH / (float)taf->tdp.nbr_col_max;
	scale_h = (float)HEIGHT / (float)taf->tdp.nbr_lines;
	taf->tdp.scale = scale_h;
	if (scale_h > scale_v)
		taf->tdp.scale = scale_v;
}

static int	reset_min_max(t_all_file *taf)
{
	taf->tdp.min.x = 0;
	taf->tdp.max.x = 0;
	taf->tdp.min.y = 0;
	taf->tdp.max.y = 0;
	return (-1);
}

void	calc_min_max(t_all_file *taf)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = reset_min_max(taf);
	while (++i < taf->tdp.nbr_lines)
	{
		j = -1;
		while (++j < taf->tdp.nbr_columns[i])
		{
			tmp = rintf(sqrtf(2) * 0.5 * (taf->tdp.pt[i][j].x
						- taf->tdp.pt[i][j].y) * taf->tdp.scale);
			if (taf->tdp.min.x > tmp)
				taf->tdp.min.x = tmp;
			if (taf->tdp.max.x < tmp)
				taf->tdp.max.x = tmp;
			tmp = rintf((taf->tdp.pt[i][j].x + taf->tdp.pt[i][j].y) / sqrt(6)
					* taf->tdp.scale - (sqrtf(2) / sqrtf(3)
						* taf->tdp.pt[i][j].z * taf->tdp.scale / 15));
			if (taf->tdp.min.y > tmp)
				taf->tdp.min.y = tmp;
			if (taf->tdp.max.y < tmp)
				taf->tdp.max.y = tmp;
		}
	}
}

void	calc_offset(t_all_file *taf)
{
	calc_min_max(taf);
	if (taf->tdp.min.x < 0)
		taf->tdp.off_left = (WIDTH - (taf->tdp.max.x - taf->tdp.min.x)) * 0.5
			- taf->tdp.min.x;
	else
		taf->tdp.off_left = (WIDTH - (taf->tdp.max.x + taf->tdp.min.x)) * 0.5;
	taf->tdp.off_up = (HEIGHT - taf->tdp.max.y) * 0.5;
}

void	calc_pixel(t_all_file *taf)
{
	size_t	i;
	size_t	j;

	taf->tdp.pixel = ft_calloc(taf->tdp.nbr_lines, sizeof(t_pixel *));
	if (ft_lstadd_void(&taf->list, taf->tdp.pixel, 0))
		fdf_exit(&taf->list, -1, strerror(errno));
	i = -1;
	while (++i < taf->tdp.nbr_lines)
	{
		j = -1;
		taf->tdp.pixel[i] = ft_calloc(taf->tdp.nbr_columns[i], sizeof(t_pixel));
		if (ft_lstadd_void(&taf->list, taf->tdp.pixel[i], 0))
			fdf_exit(&taf->list, -1, strerror(errno));
		while (++j < taf->tdp.nbr_columns[i])
		{
			taf->tdp.pixel[i][j].x = rintf(sqrt(2) * 0.5 * taf->tdp.scale
					* (taf->tdp.pt[i][j].x - taf->tdp.pt[i][j].y)
					+ taf->tdp.off_left);
			taf->tdp.pixel[i][j].y = rintf((taf->tdp.pt[i][j].x
						+ taf->tdp.pt[i][j].y) / sqrt(6) * taf->tdp.scale
					- (sqrtf(2) / sqrtf(3) * taf->tdp.pt[i][j].z
						* taf->tdp.scale / 15))
				+ taf->tdp.off_up;
		}
	}
}
