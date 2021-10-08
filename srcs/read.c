/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:13:54 by obelair           #+#    #+#             */
/*   Updated: 2021/10/07 17:23:25 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_point(t_all_file *taf, char *str)
{
	char	**tmp;
	int		x;
	int		y;

	tmp = ft_split(str, ',');
	if (ft_lstadd_dbl(&taf->list, (void **)tmp, ft_word_len(tmp), 0))
		fdf_exit(&taf->list, -1, str);
	if (ft_strisdigit(tmp[0]) || (str[0] == '-' && str != ft_strrchr(str, '-'))
		|| (tmp[1] && ft_strishexa(tmp[1], 1)))
		fdf_exit(&taf->list, 5, str);
	x = taf->data_pt.nbr_columns[taf->data_pt.nbr_lines];
	y = taf->data_pt.nbr_lines;
	taf->data_pt.point[y][x].x = x;
	taf->data_pt.point[y][x].y = y;
	taf->data_pt.point[y][x].z = ft_atoi(str);
	read_color(taf, tmp[1]);
}

void	read_line(t_all_file *taf, char *str)
{
	size_t	len;
	char	**tmp;

	tmp = ft_split(str, ' ');
	len = ft_word_len(tmp);
	taf->data_pt.point[taf->data_pt.nbr_lines] = ft_calloc(len,
			sizeof(t_vector));
	taf->data_pt.color[taf->data_pt.nbr_lines] = ft_calloc(len,
			sizeof(int));
	if (!tmp || !taf->data_pt.point[taf->data_pt.nbr_lines]
		|| !taf->data_pt.color[taf->data_pt.nbr_lines]
		|| ft_lstadd_dbl(&taf->list, (void **)tmp, ft_word_len(tmp), 0)
		|| ft_lstadd_void(&taf->list,
			taf->data_pt.point[taf->data_pt.nbr_lines], 0)
		|| ft_lstadd_void(&taf->list,
			taf->data_pt.color[taf->data_pt.nbr_lines], 0))
		fdf_exit(&taf->list, -1, strerror(errno));
	while (taf->data_pt.nbr_columns[taf->data_pt.nbr_lines] < len)
	{
		read_point(taf, tmp[taf->data_pt.nbr_columns[taf->data_pt.nbr_lines]]);
		taf->data_pt.nbr_columns[taf->data_pt.nbr_lines]++;
	}
}

void	read_map(t_all_file *taf)
{
	size_t	len;

	len = ft_word_len(taf->map);
	taf->data_pt.point = ft_calloc(len, sizeof(t_vector *));
	taf->data_pt.nbr_columns = ft_calloc(len, sizeof(size_t));
	taf->data_pt.color = ft_calloc(len, sizeof(int *));
	if (!taf->data_pt.nbr_columns || !taf->data_pt.point
		|| ft_lstadd_void(&taf->list, taf->data_pt.nbr_columns, 0)
		|| ft_lstadd_void(&taf->list, taf->data_pt.point, 0)
		|| ft_lstadd_void(&taf->list, taf->data_pt.color, 0))
		fdf_exit(&taf->list, -1, strerror(errno));
	while (taf->map[taf->data_pt.nbr_lines]
		&& taf->map[taf->data_pt.nbr_lines][0])
	{
		read_line(taf, taf->map[taf->data_pt.nbr_lines]);
		if (taf->data_pt.nbr_col_max < taf->data_pt.nbr_columns[taf->data_pt.nbr_lines])
			taf->data_pt.nbr_col_max = taf->data_pt.nbr_columns[taf->data_pt.nbr_lines];
		taf->data_pt.nbr_lines++;
	}
}

static void	read_file(t_all_file *taf, int fd)
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
		if (ft_lstadd_void(&taf->list, data, 0))
			fdf_exit(&taf->list, -1, strerror(errno));
		taf->map = ft_word_join(taf->map, data);
		if (!taf->map || rd == -1)
		{
			ft_lstadd_dbl(&taf->list, (void **)taf->map, ft_word_len(taf->map),
				0);
			fdf_exit(&taf->list, -1, strerror(errno));
		}
	}
	ft_lstadd_dbl(&taf->list, (void **)taf->map, ft_word_len(taf->map), 0);
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
	read_map(taf);
}
