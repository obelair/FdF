/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displ_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:44:58 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_display(t_format *tf, char *str)
{
	int		i;

	i = 0;
	if (tf->point)
		while (i < ft_min(tf->lenvar, tf->wprec))
			ft_putchar_fd(str[i++], tf->fd);
	else
		while (i < tf->lenvar)
			ft_putchar_fd(str[i++], tf->fd);
	if (tf->point)
		tf->nbprint += ft_min(tf->lenvar, tf->wprec);
	else
		tf->nbprint += tf->lenvar;
}

void	ft_displ_str(t_format *tf)
{
	char	*str;

	str = va_arg(*(tf->ap), char *);
	if (!str)
		str = "(null)";
	tf->lenvar = ft_strlen(str);
	if (tf->width && tf->point)
		tf->width -= ft_min(tf->lenvar, tf->wprec);
	else if (tf->width)
		tf->width -= tf->lenvar;
	if (tf->zero && !tf->minus)
		ft_displ_zero(tf, tf->width);
	else if (!tf->zero && !tf->minus)
		ft_displ_spc(tf, tf->width);
	ft_display(tf, str);
	if (tf->minus)
		ft_displ_spc(tf, tf->width);
}
