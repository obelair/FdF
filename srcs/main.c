/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:57:06 by obelair           #+#    #+#             */
/*   Updated: 2021/10/08 20:01:04 by obelair          ###   ########lyon.fr   */
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
	// int			i;
	// int			j;

	fdf_arg(&taf.list, ac, av);
	open_fdf(&taf, av[1]);
	calc_scale(&taf);
	calc_offset(&taf);
	calc_pixel(&taf);
	init_win(&taf);
	mlx_hook(taf.data.win, 17, 0L, close_win, &taf);
	mlx_hook(taf.data.win, 2, 1L << 0, key_press, &taf);
	mlx_loop_hook(taf.data.mlx, next_frame, &taf);
	mlx_loop(taf.data.mlx);
	// printf("============================\n");
	// printf("===     INFORMATIONS     ===\n");
	// printf("============================\n\n");
	// printf("Nb Lines : %zu\n", taf.data_pt.nbr_lines);
	// i = 0;
	// while (i < (int)taf.data_pt.nbr_lines)
	// {
	// 	printf("\tNb Column[%d] : %zu\n", i, taf.data_pt.nbr_lines);
	// 	i++;
	// }
	// printf("\n============================\n");
	// printf("=====      SOMMETS     =====\n");
	// printf("============================\n\n");
	// printf("\t\t ");
	// j = 0;
	// while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	// {
	// 	printf("----------------");
	// 	j++;
	// }
	// printf("---------------\n");
	// printf("\t\t|");
	// j = 0;
	// while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	// {
	// 	printf("\t[%d]\t|", j);
	// 	j++;
	// }
	// printf("\t[%d]\t|\n", j);
	// printf(" ---------------");
	// j = 0;
	// while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	// {
	// 	printf("----------------");
	// 	j++;
	// }
	// printf("----------------\n");
	// i = 0;
	// while (i < (int)taf.data_pt.nbr_lines)
	// {
	// 	printf("|\t[%d]\t|", i);
	// 	j = 0;
	// 	while (j < (int)taf.data_pt.nbr_columns[i] - 1)
	// 	{
	// 		printf("\t[%.f]\t|", taf.data_pt.point[i][j].z);
	// 		j++;
	// 	}
	// 	printf("\t[%.f]\t|\n", taf.data_pt.point[i][j].z);
	// 	i++;
	// }
	// printf(" ---------------");
	// j = 0;
	// while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	// {
	// 	printf("----------------");
	// 	j++;
	// }
	// printf("----------------\n");
	// printf("\n============================\n");
	// printf("=====      COLORS      =====\n");
	// printf("============================\n\n");
	// printf("\t\t ");
	// j = 0;
	// while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	// {
	// 	printf("------------------------");
	// 	j++;
	// }
	// printf("-----------------------\n");
	// printf("\t\t|");
	// j = 0;
	// while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	// {
	// 	printf("\t    [%d]    \t|", j);
	// 	j++;
	// }
	// printf("\t    [%d]    \t|\n", j);
	// printf(" ---------------");
	// j = 0;
	// while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	// {
	// 	printf("------------------------");
	// 	j++;
	// }
	// printf("------------------------\n");
	// i = 0;
	// while (i < (int)taf.data_pt.nbr_lines)
	// {
	// 	printf("|\t[%d]\t|", i);
	// 	j = 0;
	// 	while (j < (int)taf.data_pt.nbr_columns[i] - 1)
	// 	{
	// 		printf("\t[%d]\t|", taf.data_pt.color[i][j]);
	// 		j++;
	// 	}
	// 	printf("\t[%d]\t|\n", taf.data_pt.color[i][j]);
	// 	i++;
	// }
	// printf(" ---------------");
	// j = 0;
	// while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	// {
	// 	printf("------------------------");
	// 	j++;
	// }
	// printf("------------------------\n");
	// printf("col_max : %ld\n", taf.data_pt.nbr_col_max);
	// printf("\n============================\n");
	// printf("=====       PIXELS     =====\n");
	// printf("============================\n\n");
	// printf("\t\t ");
	// j = 0;
	// while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	// {
	// 	printf("----------------");
	// 	j++;
	// }
	// printf("---------------\n");
	// printf("\t\t|");
	// j = 0;
	// while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	// {
	// 	printf("\t[%d]\t|", j);
	// 	j++;
	// }
	// printf("\t[%d]\t|\n", j);
	// printf(" ---------------");
	// j = 0;
	// while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	// {
	// 	printf("----------------");
	// 	j++;
	// }
	// printf("----------------\n");
	// i = 0;
	// while (i < (int)taf.data_pt.nbr_lines)
	// {
	// 	printf("|\t[%d]\t|", i);
	// 	j = 0;
	// 	while (j < (int)taf.data_pt.nbr_columns[i] - 1)
	// 	{
	// 		printf("\t[%d, %d]\t|", taf.data_pt.pixel[i][j].x, taf.data_pt.pixel[i][j].y);
	// 		j++;
	// 	}
	// 	printf("\t[%d, %d]\t|\n", taf.data_pt.pixel[i][j].x, taf.data_pt.pixel[i][j].y);
	// 	i++;
	// }
	// printf(" ---------------");
	// j = 0;
	// while (j < (int)taf.data_pt.nbr_columns[0] - 1)
	// {
	// 	printf("----------------");
	// 	j++;
	// }
	// printf("----------------\n");
	ft_lstclear(&taf.list, &free);
	return (EXIT_SUCCESS);
}