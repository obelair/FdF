/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lencmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:15:55 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lencmp(t_format *tf, long long val)
{
	int	tmp;

	tmp = tf->width;
	if ((tf->width && val < 0) || tf->plus || tf->space)
		tf->width = tf->width - ft_max(tf->lenvar, tf->wprec) - 1;
	else if (tf->width
		&& (tf->spec == 'p' || (ft_strchr("xX", tf->spec) && tf->hash && val)))
		tf->width = tf->width - ft_max(tf->lenvar, tf->wprec) - 2;
	else if (tf->width)
		tf->width = tf->width - ft_max(tf->lenvar, tf->wprec);
	if (ft_strchr("diouxXp", tf->spec) && tf->point && !tf->wprec
		&& val == 0)
	{
		if (tf->width || tmp == 1)
			tf->width++;
		tf->lenvar = -1;
	}
	else if (!tf->point && !tf->wprec && tf->zero && !tf->minus)
	{
		tf->point = TRUE;
		tf->wprec = tf->width;
		tf->width = 0;
	}
	else if (tf->wprec)
		tf->wprec -= tf->lenvar;
}
