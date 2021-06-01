/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:50:50 by obelair           #+#    #+#             */
/*   Updated: 2021/06/01 14:34:30 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_exit(t_list **list, int err, char *str)
{
	write_error(err, str);
	ft_lstclear(list, &free);
	exit(EXIT_FAILURE);
}

void	fdf_arg(t_list **list, int ac, char **av)
{
	char	**tmp;

	tmp = NULL;
	*list = ft_lstnew(NULL);
	if (ac < 2)
		fdf_exit(list, 1, av[0]);
	else if (ac > 2)
		fdf_exit(list, 2, av[0]);
	if ()
}

void	write_error(int err, char *str)
{
	if (err == 1)
		printf("Error >>\n\tAn argument is missing : %s.\n", str);
	if (err == 2)
		printf("Error >>\n\tToo much argument after '%s'.\n", str);
}