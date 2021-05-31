/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:34:28 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_line(char *str)
{
	int		i;
	char	*tmp;

	if (!str)
		return (NULL);
	i = ft_strichr(str, '\n');
	if (i == -1)
		tmp = ft_substr(str, 0, ft_strlen(str));
	else
		tmp = ft_substr(str, 0, i);
	return (tmp);
}

static char	*get_keep_save(char *save)
{
	char	*keep;
	size_t	lenstr;
	int		i;

	i = ft_strichr(save, '\n');
	lenstr = ft_strlen(save);
	keep = ft_substr(save, i + 1, lenstr - i);
	if (!keep)
		return (0);
	free(save);
	return (keep);
}

static int	check_rd(int rd, int fd, char *buff, char **save)
{
	if (!buff)
		return (-1);
	while ((ft_strichr(*save, '\n') == -1) && rd)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (-1);
		buff[rd] = '\0';
		*save = ft_strjoin(*save, buff);
		if (!save)
			return (-1);
	}
	return (rd);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*save;
	int			rd;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rd = check_rd(1, fd, buff, &save);
	free(buff);
	if (fd < 0 || !line || BUFFER_SIZE < 1 || rd == -1)
		return (-1);
	*line = get_line(save);
	if (!*line)
		return (-1);
	save = get_keep_save(save);
	if (!save)
		return (-1);
	if (!rd)
	{
		free(save);
		save = NULL;
		return (0);
	}
	return (1);
}
