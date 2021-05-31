/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:33 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_define(void)
{
	if (TRUE != 1 || FALSE != 0
		|| ft_strcmp(B8, "01234567")
		|| ft_strcmp(B10, "0123456789")
		|| ft_strcmp(B16L, "0123456789abcdef")
		|| ft_strcmp(B16U, "0123456789ABCDEF"))
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		param_info;
	t_format	form;
	int			i;

	if (check_define())
		return (-1);
	va_start(param_info, str);
	form.nbprint = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			form.nbprint++;
		}
		else
		{
			ft_init_struct(&param_info, &form, 1);
			i += ft_scan_str(&form, str + i);
		}
		i++;
	}
	va_end(param_info);
	return (form.nbprint);
}
