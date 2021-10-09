/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:57:06 by obelair           #+#    #+#             */
/*   Updated: 2021/10/09 17:41:35 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_win(t_all_file *taf)
{
	mlx_destroy_window(taf->data.mlx, taf->data.win);
	ft_lstclear(&taf->list, &free);
	exit(EXIT_SUCCESS);
}

static int	key_press(int key, t_all_file *taf)
{
	if (key == ESC)
		close_win(taf);
	move(taf, key);
	zoom(taf, key);
	return (0);
}

int	main(int ac, char **av)
{
	t_all_file	taf;

	fdf_arg(&taf.list, ac, av);
	open_fdf(&taf, av[1]);
	calc_scale(&taf);
	calc_offset(&taf);
	init_win(&taf);
	mlx_hook(taf.data.win, 17, 0L, close_win, &taf);
	mlx_hook(taf.data.win, 2, 1L << 0, key_press, &taf);
	mlx_loop_hook(taf.data.mlx, next_frame, &taf);
	mlx_loop(taf.data.mlx);
	ft_lstclear(&taf.list, &free);
	return (EXIT_SUCCESS);
}
