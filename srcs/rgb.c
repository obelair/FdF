/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:49:00 by obelair           #+#    #+#             */
/*   Updated: 2021/06/23 09:55:06 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	asc_to_rgb(t_all_file *taf, char *color)
{
	int	rgb;
	int	len;
	int	nb;
	int	i;

	i = ft_strlen(color) - 1;
	if (i > 5 || i < 0 || !(i % 2))
		return (-1);
	if (i != 5)
	{
		if (ft_lstadd_void(&taf->list, color, 0))
			fdf_exit(&taf->list, -1, strerror(errno));
	}
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
		taf->data_pt.color[line][col] = asc_to_rgb(taf, color + 2);
		printf("Color : %d\n", taf->data_pt.color[line][col]);
		if (taf->data_pt.color[line][col] < 0)
			fdf_exit(&taf->list, 5, color);
	}
}
