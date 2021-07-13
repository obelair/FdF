/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:49:00 by obelair           #+#    #+#             */
/*   Updated: 2021/07/13 14:22:36 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	asc_to_rgb(char *color)
{
	int	rgb;
	int	len;
	int	nb;
	int	i;

	i = ft_strlen(color) - 1;
	if (i > 5 || i < 0 || !(i % 2))
		return (-1);
	len = i;
	while (i >= 0)
	{
		nb = ft_max(ft_strichr(B16L, color[i]), ft_strichr(B16U, color[i]));
		if (nb < 0)
			return (-1);
		rgb = rgb + nb * pow(16, len - i);
		i--;
	}
	return (rgb);
}

void	read_color(t_all_file *taf, char *color)
{
	int	col;
	int	line;

	line = taf->data_pt.nbr_lines;
	col = taf->data_pt.nbr_columns[taf->data_pt.nbr_lines];
	if (!color)
		taf->data_pt.color[line][col] = 0xFFFFFF;
	else
	{
		taf->data_pt.color[line][col] = asc_to_rgb(color + 2);
		// printf("Str : %s | Color : %d\n", color + 2, taf->data_pt.color[line][col]);
		if (taf->data_pt.color[line][col] < 0)
			fdf_exit(&taf->list, 5, color);
	}
}
