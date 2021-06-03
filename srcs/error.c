/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:50:50 by obelair           #+#    #+#             */
/*   Updated: 2021/06/03 13:43:09 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	write_error(int err, char *str)
{
	if (err == 1)
		printf("Error >>\n\tAn argument is missing : %s.\n", str);
	else if (err == 2)
		printf("Error >>\n\tToo much argument after '%s'.\n", str);
	else if (err == 3)
		printf("Error >>\n\tExtension '%s' not recognized.\n", str);
	else if (err == 4)
		printf("Error >>\n\tFile '%s' doesn't exist.\n", str);
	else
		printf("Error >>\n\t%s\n", str);
}

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
	if (ft_strchr(av[ac - 1], '.'))
	{
		tmp = ft_split(av[ac - 1], '.');
		lstadd_dbl(list, tmp);
		if (ft_strcmp(tmp[ft_nbr_word(tmp) - 1], "fdf"))
			fdf_exit(list, 3, tmp[ft_nbr_word(tmp) - 1]);
		else if (!tmp[1] || ft_strnstr(av[1], "/.fdf", ft_strlen(av[1])))
			fdf_exit(list, 4, av[1]);
	}
	else
		fdf_exit(list, 4, av[ac - 1]);
}
