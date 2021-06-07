/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:09:55 by obelair           #+#    #+#             */
/*   Updated: 2021/06/07 14:54:01 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_struct(t_all_file *taf)
{
	taf->res.height = HEIGHT;
	taf->res.width = WIDTH;
	taf->map = NULL;
	taf->data_pt.point = NULL;
	taf->data_pt.nbr_lines = 0;
	taf->data_pt.nbr_columns = NULL;
}
