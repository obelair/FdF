/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displ_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 09:09:08 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_displ_addr(t_format *tf, char *base)
{
	unsigned long long	val;

	val = va_arg(*(tf->ap), unsigned long long);
	tf->lenvar = ft_uintblen(val, ft_strlen(base));
	tf->base = base;
	ft_lencmp(tf, val);
	if (((tf->zero && !tf->minus) || (!tf->zero && !tf->minus)))
		ft_displ_spc(tf, tf->width);
	ft_putstr_fd("0x", tf->fd);
	tf->nbprint += 2;
	if (tf->wprec)
		ft_displ_zero(tf, tf->wprec);
	ft_displ_nbr(tf, val);
	if (tf->minus)
		ft_displ_spc(tf, tf->width);
}
