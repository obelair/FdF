/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:00:17 by obelair           #+#    #+#             */
/*   Updated: 2021/06/23 10:58:56 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_win(t_all_file *taf)
{
	taf->data.mlx = 0;
	taf->data.win = 0;
	taf->data.mlx = mlx_init();
	taf->data.win = mlx_new_window(taf->data.mlx,
			WIDTH, HEIGHT, "FdF");
	if (!taf->data.mlx || !taf->data.win)
		fdf_exit(&taf->list, -1, strerror(errno));
}

void	init_img(t_all_file *taf)
{
	taf->data.img = mlx_new_image(taf->data.mlx, WIDTH,
			HEIGHT);
	taf->data.addr = mlx_get_data_addr(taf->data.img,
			&taf->data.bits_per_pixel,
			&taf->data.line_length, &taf->data.endian);
	if (!taf->data.img || !taf->data.addr)
		fdf_exit(&taf->list, -1, strerror(errno));
}
