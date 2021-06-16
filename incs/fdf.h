/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:44:39 by obelair           #+#    #+#             */
/*   Updated: 2021/06/16 17:32:11 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "ft_vector.h"
# include "mlx.h"

# ifdef __APPLE__
#  define ESC	53
# else
#  define ESC	65307
# endif

# define WIDTH	1024
# define HEIGHT	768

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_resolution
{
	int	width;
	int	height;
}	t_resolution;

typedef struct s_data_point
{
	t_vector	**point;
	int			**color;
	size_t		nbr_lines;
	size_t		*nbr_columns;
}	t_data_point;

typedef struct s_all_file
{
	t_list			*list;
	char			**map;
	t_data			data;
	t_data_point	data_pt;
	t_resolution	res;
}	t_all_file;

void	write_error(int err, char *str);
void	fdf_exit(t_list **list, int err, char *str);
void	fdf_arg(t_list **list, int ac, char **av);

void	init_struct(t_all_file *taf);

void	open_fdf(t_all_file *taf, char *file);

#endif
