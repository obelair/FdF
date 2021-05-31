/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displ_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:38:17 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_display(t_format *tf, long long val)
{
	if (!tf->minus && tf->width)
		ft_displ_spc(tf, tf->width);
	ft_displ_pre(tf, &val);
	if (tf->point)
		ft_displ_zero(tf, tf->wprec);
	ft_displ_nbr(tf, val);
	if (tf->minus)
		ft_displ_spc(tf, tf->width);
}

void	ft_displ_int(t_format *tf, char *base)
{
	long long	val;

	if (ft_strchr("di", tf->spec))
		val = va_arg(*(tf->ap), int);
	else
		val = va_arg(*(tf->ap), unsigned int);
	if (ft_strchr("di", tf->spec))
		tf->lenvar = ft_intblen(val, ft_strlen(base));
	else
		tf->lenvar = ft_uintblen(val, ft_strlen(base));
	tf->base = base;
	ft_lencmp(tf, val);
	ft_display(tf, val);
}
