/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:47:28 by obelair           #+#    #+#             */
/*   Updated: 2021/10/08 20:01:31 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_scale(t_all_file *taf)
{
	float	scale_v;
	float	scale_h;

	scale_v = (float)WIDTH / (float)taf->data_pt.nbr_col_max;
	scale_h = (float)HEIGHT / (float)taf->data_pt.nbr_lines;
	// printf("Sc_v : %.2f | Sc_h : %.2f\n", scale_v, scale_h);
	taf->data_pt.scale = scale_h - 5;
	if (scale_h > scale_v)
		taf->data_pt.scale = scale_v - 5;
}

static void	calc_min_max(t_all_file *taf, int min[2], int max[2])
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < taf->data_pt.nbr_lines)
	{
		j = 0;
		while (j < taf->data_pt.nbr_columns[i])
		{
			tmp = rintf((sqrtf(2) * 0.5 * (taf->data_pt.point[i][j].x - taf->data_pt.point[i][j].y)) * taf->data_pt.scale);
			// printf("[%ld,%ld] x : %d |", i, j, tmp);
			if (min[0] > tmp)
				min[0] = tmp;
			if (max[0] < tmp)
				max[0] = tmp;
			tmp = -1 * rintf((((-1 * (1 / sqrt(6)) * (taf->data_pt.point[i][j].x + taf->data_pt.point[i][j].y)) * taf->data_pt.scale) + ((sqrtf(2) / sqrtf(3) * taf->data_pt.point[i][j].z)) * 3));
			// printf(" y : %d\n", tmp);
			if (min[1] > tmp)
				min[1] = tmp;
			if (max[1] < tmp)
				max[1] = tmp;
			j++;
		}
		i++;
	}
}

void	calc_offset(t_all_file *taf)
{
	int	max[2];
	int	min[2];

	min[0] = rintf((sqrtf(2) * 0.5 * (taf->data_pt.point[0][0].x - taf->data_pt.point[0][0].y)));
	max[0] = min[0];
	min[1] = -1 * rintf((((-1 / sqrtf(6)) * (taf->data_pt.point[0][0].x + taf->data_pt.point[0][0].y)) + ((sqrtf(2) / sqrtf(3)) * taf->data_pt.point[0][0].z)));
	max[1] = min[1];
	calc_min_max(taf, min, max);
	// printf("x_min : %d | x_max : %d | y_min : %d | y_max : %d\n", min[0], max[0], min[1], max[1]);
	if (min[0] < 0)
		taf->data_pt.off_left = (WIDTH - (max[0] - min[0])) * 0.5 - min[0];
	else
		taf->data_pt.off_left = (WIDTH - (max[0] + min[0])) * 0.5;
	// if (max[1] >= HEIGHT)
	// 	taf->data_pt.off_up = (max[1] - HEIGHT) * 0.5;
	// else
		taf->data_pt.off_up = (HEIGHT - max[1]) * 0.5;
	// printf("left : %f | up : %f\n", taf->data_pt.off_left, taf->data_pt.off_up);
}

void	calc_pixel(t_all_file *taf)
{
	size_t	i;
	size_t	j;

	taf->data_pt.pixel = ft_calloc(taf->data_pt.nbr_lines, sizeof(t_pixel *));
	if (ft_lstadd_void(&taf->list, taf->data_pt.pixel, 0))
		fdf_exit(&taf->list, -1, strerror(errno));
	i = 0;
	while (i < taf->data_pt.nbr_lines)
	{
		j = 0;
		taf->data_pt.pixel[i] = ft_calloc(taf->data_pt.nbr_columns[i], sizeof(t_pixel));
		if (ft_lstadd_void(&taf->list, taf->data_pt.pixel[i], 0))
			fdf_exit(&taf->list, -1, strerror(errno));
		while (j < taf->data_pt.nbr_columns[i])
		{
			// if (i == 2 && j == 2)
			// 	printf("[%.f,%.f,%.f] scale : %f | off : %f | -1/sqrt(6)*(x+y) = %f | sqrt(2/3)*z = %f | scale = %f | off = %f\n", taf->data_pt.point[i][j].x, taf->data_pt.point[i][j].y, taf->data_pt.point[i][j].z, taf->data_pt.scale, taf->data_pt.off_up, (-1 * (1 / sqrt(6)) * (taf->data_pt.point[i][j].x + taf->data_pt.point[i][j].y)), (sqrtf(2) / sqrtf(3) * taf->data_pt.point[i][j].z), ((-1 * (1 / sqrt(6)) * (taf->data_pt.point[i][j].x + taf->data_pt.point[i][j].y)) + (sqrtf(2 / 3) * taf->data_pt.point[i][j].z)) * taf->data_pt.scale, ((-1 * (1 / sqrt(6)) * (taf->data_pt.point[i][j].x + taf->data_pt.point[i][j].y)) + (sqrtf(2 / 3) * taf->data_pt.point[i][j].z)) * taf->data_pt.scale + taf->data_pt.off_up);
			taf->data_pt.pixel[i][j].x = rintf((sqrt(2) * 0.5 * (taf->data_pt.point[i][j].x - taf->data_pt.point[i][j].y)) * taf->data_pt.scale + taf->data_pt.off_left);
			taf->data_pt.pixel[i][j].y = -1 * rintf((((-1 * (1 / sqrt(6)) * (taf->data_pt.point[i][j].x + taf->data_pt.point[i][j].y)) * taf->data_pt.scale) + ((sqrtf(2) / sqrtf(3) * taf->data_pt.point[i][j].z)) * 3)) + taf->data_pt.off_up;
			j++;
		}
		i++;
	}
}