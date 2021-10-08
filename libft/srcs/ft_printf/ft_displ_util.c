/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displ_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:59:34 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_displ_spc(t_format *tf, int i)
{
	while (0 < i)
	{
		ft_putchar_fd(' ', tf->fd);
		tf->nbprint++;
		i--;
	}
}

void	ft_displ_zero(t_format *tf, int i)
{
	while (0 < i)
	{
		ft_putchar_fd('0', tf->fd);
		tf->nbprint++;
		i--;
	}
}

void	ft_displ_pre(t_format *tf, long long *val)
{
	if (*val < 0)
	{
		ft_putchar_fd('-', tf->fd);
		tf->nbprint++;
		*val = -(*val);
	}
	else if (tf->plus || tf->space)
	{
		if (tf->plus)
			ft_putchar_fd('+', tf->fd);
		else
			ft_putchar_fd(' ', tf->fd);
		tf->nbprint++;
	}
	else if (ft_strchr("xX", tf->spec) && tf->hash && *val)
	{
		if (tf->spec == 'x')
			ft_putstr_fd("0x", tf->fd);
		else
			ft_putstr_fd("0X", tf->fd);
		tf->nbprint += 2;
	}
}

void	ft_displ_nbr(t_format *tf, unsigned long long val)
{
	if (tf->lenvar < 0)
		return ;
	if (val > ft_strlen(tf->base) - 1)
		ft_displ_nbr(tf, val / ft_strlen(tf->base));
	ft_putchar_fd((tf->base[val % ft_strlen(tf->base)]), tf->fd);
	tf->nbprint++;
}
