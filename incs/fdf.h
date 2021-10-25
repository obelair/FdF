/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:44:39 by obelair           #+#    #+#             */
/*   Updated: 2021/10/25 14:53:32 by obelair          ###   ########lyon.fr   */
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
#  define LEFT	123
#  define RIGHT	124
#  define ESC	53
#  define W		13
#  define S		1
#  define A		0
#  define D		2
#  define I		34
#  define O		31
# else
#  define LEFT	65361
#  define RIGHT	65363
#  define ESC	65307
#  define W		122
#  define S		115
#  define A		113
#  define D		100
#  define I		105
#  define O		111
# endif

# define WIDTH	1024
# define HEIGHT	700
# define B16U	"0123456789ABCDEF"
# define B16L	"0123456789abcdef"

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

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_data_point
{
	t_vector	**pt;
	int			**color;
	t_pixel		**pixel;
	float		scale;
	float		off_left;
	float		off_up;
	size_t		nbr_lines;
	size_t		*nbr_columns;
	size_t		nbr_col_max;
	t_pixel		min;
	t_pixel		max;
}	t_data_point;

typedef struct s_all_file
{
	t_list			*list;
	char			**map;
	t_data			data;
	t_data_point	tdp;
}	t_all_file;

void	write_error(int err, char *str);
void	fdf_exit(t_list **list, int err, char *str);
void	fdf_arg(t_list **list, int ac, char **av);

void	init_struct(t_all_file *taf);
void	init_win(t_all_file *taf);
void	init_img(t_all_file *taf);

void	open_fdf(t_all_file *taf, char *file);

void	read_color(t_all_file *taf, char *color);

void	calc_scale(t_all_file *taf);
void	calc_min_max(t_all_file *taf);
void	calc_offset(t_all_file *taf);
void	calc_pixel(t_all_file *taf);

void	move(t_all_file *taf, int key);
void	zoom(t_all_file *taf, int key);

int		next_frame(t_all_file *taf);

#endif
