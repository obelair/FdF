/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:13:54 by obelair           #+#    #+#             */
/*   Updated: 2021/06/08 17:56:00 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_line(t_all_file *taf, char *str, size_t len)
{
	int	line;
	int	col;
	int	i;

	line = taf->data_pt.nbr_lines;
	col = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			fdf_exit(&taf->list, 5, str);
		taf->data_pt.point[line][col].x = col;
		taf->data_pt.point[line][col].y = line;
		taf->data_pt.point[line][col].z = ft_atoi(str + i);
		col++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] != ' ')
			fdf_exit(&taf->list, 5, str);
		i++;
	}
	taf->data_pt.nbr_columns[line] = col;
}

void	read_map(t_all_file *taf)
{
	size_t	len;
	char	**tmp;

	len = ft_word_len(taf->map);
	taf->data_pt.point = ft_calloc(len, sizeof(t_vector *));
	taf->data_pt.nbr_columns = ft_calloc(len, sizeof(int));
	if (!taf->data_pt.nbr_columns || !taf->data_pt.point
		|| ft_lstadd_void(&taf->list, taf->data_pt.nbr_columns, 0)
		|| ft_lstadd_void(&taf->list, taf->data_pt.point, 0))
		fdf_exit(&taf->list, -1, strerror(errno));
	while (taf->map[taf->data_pt.nbr_lines])
	{
		tmp = ft_split(taf->map[taf->data_pt.nbr_lines], ' ');
		len = ft_word_len(tmp);
		taf->data_pt.point[taf->data_pt.nbr_lines] = ft_calloc(len,
				sizeof(t_vector));
		if (!tmp || taf->data_pt.point[taf->data_pt.nbr_lines]
			|| ft_lstadd_dbl(&taf->list, (void **)tmp, len, 0)
			|| ft_lstadd_void(&taf->list,
				taf->data_pt.point[taf->data_pt.nbr_lines], 0))
			fdf_exit(&taf->list, -1, strerror(errno));
		read_line(taf, taf->map[taf->data_pt.nbr_lines], len);
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
		taf->map = ft_word_join(taf->map, data);
		if (!taf->map || rd == -1)
		{
			ft_lstadd_dbl(&taf->list, (void **)taf->map,
				ft_word_len(taf->map), 0);
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
