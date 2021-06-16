/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:57:06 by obelair           #+#    #+#             */
/*   Updated: 2021/06/09 08:56:43 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static int	close_win(t_all_file *taf)
// {
// 	mlx_destroy_window(taf->data.mlx, taf->data.win);
// 	ft_lstclear(&taf->list, &free);
// 	return (EXIT_SUCCESS);
// }

// static int	key_press(int key, t_all_file *taf)
// {
// 	if (key == ESC)
// 		close_win(taf);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_all_file	taf;
	int			i;
	int			j;
	/*
	- Verifier les arguments
	- Recuperer les donnees d'un fichier .fdf
	- faire des loops pour l'affichage 
	- calculer les segments
	- afficher les segments
	- faire en sorte que la croix et la touche ESC quitte le programme
	*/
	fdf_arg(&taf.list, ac, av);
	open_fdf(&taf, av[1]);
	printf("============================\n");
	printf("=====      SOMMETS     =====\n");
	printf("============================\n");
	printf("    |");
	j = 0;
	while (j < taf.data_pt.nbr_columns[0] - 1)
	{
		if (j < 10)
			printf(" [%d]  |", j);
		else
			printf(" [%d] |", j);
		j++;
	}
	printf(" [%d]\n", j);
	i = 0;
	while (i < taf.data_pt.nbr_lines)
	{
		if (i < 10)
			printf(" [%d]  |", i);
		else
			printf(" [%d] |", i);
		j = 0;
		while (j < taf.data_pt.nbr_columns[i] - 1)
		{
			printf("");
		}
	}
	// init_win(&taf);
	// mlx_hook(taf.data.win, 17, 0L, close_win, &taf);
	// mlx_hook(taf.data.win, 2, 1L << 0, key_press, &taf);
	// mlx_loop_hook(taf.data.mlx, next_frame, &taf);
	// mlx_loop(taf.data.mlx);
	ft_lstclear(&taf.list, &free);
	return (EXIT_SUCCESS);
}