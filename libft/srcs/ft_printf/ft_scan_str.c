/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:28:09 by obelair           #+#    #+#             */
/*   Updated: 2021/05/14 09:55:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spec(t_format *tf, const char *str, int i)
{
	tf->spec = str[i++];
	if (ft_strchr("diu", tf->spec))
		ft_displ_int(tf, B10);
	else if (tf->spec == 'o')
		ft_displ_int(tf, B8);
	else if (tf->spec == 'x')
		ft_displ_int(tf, B16L);
	else if (tf->spec == 'X')
		ft_displ_int(tf, B16U);
	else if (tf->spec == 'p')
		ft_displ_addr(tf, B16L);
	else if (tf->spec == 's')
		ft_displ_str(tf);
	else if (ft_strchr("c%", tf->spec))
		ft_displ_chr(tf);
	else if (tf->spec == 'n')
		ft_nptr(tf);
	i++;
	return (i);
}

static int	ft_length(t_format *tf, const char *str, int i)
{
	if (str[i] == 'l')
	{
		i++;
		if (str[i] == 'l')
			i++;
	}
	else if (str[i] == 'h')
	{
		i++;
		if (str[i] == 'h')
			i++;
	}
	return (ft_spec(tf, str, i));
}

static int	ft_prec(t_format *tf, const char *str, int i)
{
	if (str[i] == '.')
	{
		tf->point = TRUE;
		i++;
		if (str[i] == '*')
		{
			tf->wprec = va_arg(*(tf->ap), int);
			i++;
		}
		else if (ft_isdigit(str[i]) || str[i] == '-')
		{
			tf->wprec = ft_atoi(str + i);
			if (str[i] == '-')
				i++;
			while (ft_isdigit(str[i]))
				i++;
		}
		if (tf->wprec < 0)
		{
			tf->point = FALSE;
			tf->wprec = 0;
		}
	}
	return (ft_length(tf, str, i));
}

static int	ft_width(t_format *tf, const char *str, int i)
{
	if (str[i] == '*')
	{
		tf->width = va_arg(*(tf->ap), int);
		i++;
	}
	else if (ft_isdigit(str[i]))
	{
		tf->width = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	if (tf->width < 0)
	{
		tf->minus = TRUE;
		tf->width *= -1;
	}
	return (ft_prec(tf, str, i));
}

int	ft_scan_str(t_format *tf, const char *str)
{
	int	i;

	i = 0;
	while (ft_strchr("-0 +#", str[i]))
	{
		if (str[i] == '-')
			tf->minus = TRUE;
		if (str[i] == '0')
			tf->zero = TRUE;
		if (str[i] == ' ')
			tf->space = TRUE;
		if (str[i] == '#')
			tf->hash = TRUE;
		if (str[i] == '+')
			tf->plus = TRUE;
		i++;
	}
	return (ft_width(tf, str, i));
}
