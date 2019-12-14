/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisher <alisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:48:19 by cjinn             #+#    #+#             */
/*   Updated: 2019/12/10 15:16:26 by alisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrf(int n, int *p)
{
	if (n < 0)
	{
		*p = *p + 1;
		ft_putchar('-');
		n = -n;
	}
	if (n == -2147483648)
	{
		ft_putchar('2');
		n = n % 1000000000;
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbrf((n / 10), p);
		ft_putnbrf((n % 10), p);
	}
	else
	{
		*p = *p + 1;
		ft_putchar(n + '0');
	}
}
