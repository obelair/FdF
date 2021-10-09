/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:35:07 by obelair           #+#    #+#             */
/*   Updated: 2021/10/09 19:24:58 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(t_all_file *taf, int key)
{
	if (key == A)
		taf->tdp.off_left -= (WIDTH / 100);
	if (key == D)
		taf->tdp.off_left += (WIDTH / 100);
	if (key == W)
		taf->tdp.off_up -= (HEIGHT / 100);
	if (key == S)
		taf->tdp.off_up += (HEIGHT / 100);
}

void	zoom(t_all_file *taf, int key)
{
	int	tmp;

	tmp = taf->tdp.max.y;
	if (key == I && taf->tdp.scale < 100)
	{
		taf->tdp.scale += 0.5;
		calc_min_max(taf);
		taf->tdp.off_up = taf->tdp.off_up - ((taf->tdp.max.y - tmp) * 0.5);
	}
	if (key == O && taf->tdp.scale > 1)
	{
		taf->tdp.scale -= 0.5;
		calc_min_max(taf);
		taf->tdp.off_up = taf->tdp.off_up + ((tmp - taf->tdp.max.y) * 0.5);
	}
}
