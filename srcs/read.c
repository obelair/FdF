/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:13:54 by obelair           #+#    #+#             */
/*   Updated: 2021/06/04 14:38:27 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_line(t_all_file *taf, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
		{
			
		}
		i++;
	}
}

int	read_file(t_all_file *taf, int fd)
{
	char	*line;
	int		rd;

	rd = 1;
	while (rd == 1)
	{
		rd = get_next_line(fd, &line);
		if (ft_lstadd_void(taf->list, line, 0))
			fdf_exit(taf->list, -1, strerror(errno));
	}
	return (0);
}

int	open_fdf(t_all_file *taf, char *file)
{
	int	fd;
	int	err;

	create_struct(taf);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		fdf_exit(&taf->list, fd, strerror(errno));
	err = read_data(fd, taf);
	close(fd);
	if (err)
		fdf_exit(&taf->list, err, strerror(errno));
	check_all(taf);
	return (0);
}
