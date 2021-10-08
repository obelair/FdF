/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:49:31 by obelair           #+#    #+#             */
/*   Updated: 2021/09/06 21:46:49 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intblen(long long n, long long base)
{
	long long	nb;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		return (ft_intblen(nb, base) + 1);
	}
	if (nb < base)
		return (1);
	return (ft_intblen(nb / base, base) + 1);
}

int	ft_uintblen(unsigned long long n, unsigned long long base)
{
	if (n < base)
		return (1);
	return (ft_intblen(n / base, base) + 1);
}
