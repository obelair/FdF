/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displ_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:54:04 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_displ_chr(t_format *tf)
{
	char	c;

	if (tf->spec == 'c')
		c = va_arg(*(tf->ap), int);
	else
		c = '%';
	tf->lenvar = 1;
	tf->width--;
	if (tf->zero && !tf->minus)
		ft_displ_zero(tf, tf->width);
	else if (!tf->zero && !tf->minus)
		ft_displ_spc(tf, tf->width);
	ft_putchar_fd(c, tf->fd);
	if (tf->minus)
		ft_displ_spc(tf, tf->width);
	tf->nbprint++;
}
