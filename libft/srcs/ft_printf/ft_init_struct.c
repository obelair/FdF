/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:26:23 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_struct(va_list *ap, t_format *tf, int fd)
{
	tf->ap = ap;
	tf->minus = FALSE;
	tf->zero = FALSE;
	tf->hash = FALSE;
	tf->space = FALSE;
	tf->plus = FALSE;
	tf->point = FALSE;
	tf->spec = 0;
	tf->wprec = 0;
	tf->width = 0;
	tf->lenvar = 0;
	tf->base = 0;
	tf->fd = fd;
}
