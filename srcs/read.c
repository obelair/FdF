/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:13:54 by obelair           #+#    #+#             */
/*   Updated: 2021/06/07 17:31:36 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	read_line(t_all_file *taf, char *data)
// {
// 	int	i;
// 	int	col;
// 	int	line;

// 	i = 0;
// 	col = 0;
// 	line = taf->data_pt.nbr_lines;
// 	while (data[i])
// 	{
// 		if (!ft_isdigit(data[i]))
// 			fdf_exit(&taf->list, 5, data);
// 		else
// 		{
// 			taf->data_pt.point[line][col].x = col;
// 			taf->data_pt.point[line][col].y = line;
// 			taf->data_pt.point[line][col].z = ft_atoi(data[i]);
// 			col++;
// 			while (ft_isdigit(data[i]))
// 				i++;
// 		}
// 		if (data[i] == ' ')
// 			i++;
// 		else
// 			fdf_exit(&taf->list, 5, data);
// 	}
// 	taf->data_pt.nbr_columns[line] = col;
// }

void	read_file(t_all_file *taf, int fd)
{
	char	*data;
	int		rd;

	rd = 1;
	taf->map = ft_calloc(1, sizeof(char *));
	if (!taf->map)
		fdf_exit(&taf->list, -1, strerror(errno));
	while (rd == 1)
	{
		rd = get_next_line(fd, &data);
		taf->map = ft_word_join(taf->map, data);
		taf->data_pt.nbr_lines++;
		if (!taf->map || rd == -1)
		{
			ft_lstadd_dbl(&taf->list, (void **)taf->map, taf->data_pt.nbr_lines, 0);
			fdf_exit(&taf->list, -1, strerror(errno));
		}
	}
	ft_lstadd_dbl(&taf->list, (void **)taf->map, taf->data_pt.nbr_lines, 0);
}

void	open_fdf(t_all_file *taf, char *file)
{
	int	fd;

	init_struct(taf);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		fdf_exit(&taf->list, fd, strerror(errno));
	read_file(taf, fd);
	close(fd);
}
