/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positive_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisher <alisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:58:57 by alisher           #+#    #+#             */
/*   Updated: 2019/12/13 15:53:01 by alisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_str_len(long long int nb)
{
	size_t	i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

char		*ft_universal_itoa(long long int n)
{
	char                    *str;
	size_t                  len;
	long long int	nb;

	nb = n;
	if (n < 0)
		nb = -n;
	len = ft_str_len(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = nb % 10 + '0';
	while (nb /= 10)
		str[--len] = nb % 10 + '0';
	return (str);
}
