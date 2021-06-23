/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:57:06 by obelair           #+#    #+#             */
/*   Updated: 2021/06/23 10:53:18 by obelair          ###   ########lyon.fr   */
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
	return (0);
}

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
	printf("===     INFORMATIONS     ===\n");
	printf("============================\n\n");
	printf("Nb Lines : %zu\n", taf.data_pt.nbr_lines);
	i = 0;
	while (i < (int)taf.data_pt.nbr_lines)
	{
		printf("\tNb Column[%d] : %zu\n", i, taf.data_pt.nbr_lines);
		i++;
	}
	printf("\n============================\n");
	printf("=====      SOMMETS     =====\n");
	printf("============================\n\n");
	printf("\t\t ");
	j = 0;
	while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	{
		printf("----------------");
		j++;
	}
	printf("---------------\n");
	printf("\t\t|");
	j = 0;
	while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	{
		printf("\t[%d]\t|", j);
		j++;
	}
	printf("\t[%d]\t|\n", j);
	printf(" ---------------");
	j = 0;
	while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	{
		printf("----------------");
		j++;
	}
	printf("----------------\n");
	i = 0;
	while (i < (int)taf.data_pt.nbr_lines)
	{
		printf("|\t[%d]\t|", i);
		j = 0;
		while (j < (int)taf.data_pt.nbr_columns[i] - 1)
		{
			printf("\t[%.f]\t|", taf.data_pt.point[i][j].z);
			j++;
		}
		printf("\t[%.f]\t|\n", taf.data_pt.point[i][j].z);
		i++;
	}
	printf(" ---------------");
	j = 0;
	while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	{
		printf("----------------");
		j++;
	}
	printf("----------------\n");
	printf("\n============================\n");
	printf("=====      COLORS      =====\n");
	printf("============================\n\n");
	printf("\t\t ");
	j = 0;
	while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	{
		printf("------------------------");
		j++;
	}
	printf("-----------------------\n");
	printf("\t\t|");
	j = 0;
	while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	{
		printf("\t    [%d]    \t|", j);
		j++;
	}
	printf("\t    [%d]    \t|\n", j);
	printf(" ---------------");
	j = 0;
	while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	{
		printf("------------------------");
		j++;
	}
	printf("------------------------\n");
	i = 0;
	while (i < (int)taf.data_pt.nbr_lines)
	{
		printf("|\t[%d]\t|", i);
		j = 0;
		while (j < (int)taf.data_pt.nbr_columns[i] - 1)
		{
			printf("\t[%d]\t|", taf.data_pt.color[i][j]);
			j++;
		}
		printf("\t[%d]\t|\n", taf.data_pt.color[i][j]);
		i++;
	}
	printf(" ---------------");
	j = 0;
	while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	{
		printf("------------------------");
		j++;
	}
	printf("------------------------\n");
	init_win(&taf);
	mlx_hook(taf.data.win, 17, 0L, close_win, &taf);
	mlx_hook(taf.data.win, 2, 1L << 0, key_press, &taf);
	mlx_loop_hook(taf.data.mlx, next_frame, &taf);
	mlx_loop(taf.data.mlx);
	ft_lstclear(&taf.list, &free);
	return (EXIT_SUCCESS);
}