/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:09:55 by obelair           #+#    #+#             */
/*   Updated: 2021/10/09 14:14:34 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_struct(t_all_file *taf)
{
	taf->map = NULL;
	taf->tdp.pt = NULL;
	taf->tdp.pixel = NULL;
	taf->tdp.nbr_lines = 0;
	taf->tdp.nbr_columns = NULL;
	taf->tdp.nbr_col_max = 0;
}
