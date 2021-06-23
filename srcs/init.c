/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:09:55 by obelair           #+#    #+#             */
/*   Updated: 2021/06/22 17:12:03 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_struct(t_all_file *taf)
{
	taf->map = NULL;
	taf->data_pt.point = NULL;
	taf->data_pt.nbr_lines = 0;
	taf->data_pt.nbr_columns = NULL;
}
