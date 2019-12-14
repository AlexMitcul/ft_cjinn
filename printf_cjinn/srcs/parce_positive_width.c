/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_positive_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisher <alisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 00:26:09 by alisher           #+#    #+#             */
/*   Updated: 2019/12/14 05:29:43 by alisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf        *ft_positive_width1(t_printf *our_str)
{
    if (our_str->negative_d == '-')
	{
		our_str->z = our_str->width - our_str->ranks - our_str->precision - 1;
		if (our_str->convert_flags[3] != '0')
            ft_positive_width2(our_str);
		else
            ft_positive_width3(our_str);
	}
	else
	{
		our_str->z = our_str->width - our_str->precision;
		if (our_str->convert_flags[3] != '0')
        {
            ft_positive_width4(our_str);
        }
		else
        {
            ft_positive_width5(our_str);
        }
    }
        return (our_str);
}

t_printf    *ft_positive_width2(t_printf *our_str)
{		
	while (our_str->z > 0)
	{
	    ft_putchar(' ');
		our_str->z--;
		our_str->len++;
    }
	ft_putchar('-');
	our_str->len++;
	return (our_str);
}

t_printf    *ft_positive_width3(t_printf *our_str)
{
	ft_putchar('-');
	while (our_str->z > 0)
	{
		ft_putchar('0');
		our_str->z--;
		our_str->len++;
	}
	our_str->len++;
    return(our_str);
}

t_printf        *ft_positive_width4(t_printf *our_str)
{
	if (our_str->convert_flags[1] == '+')
		our_str->z--;
    if (our_str->precision == 0)
    {
        our_str->z = our_str->z - our_str->ranks;
    }
	while (our_str->z > 0)
	{
        if (our_str->convert_flags[3] == '0')
        {
		    ft_putchar('0');
        }
        if (our_str->convert_flags[3] != '0')
        {
                ft_putchar(' ');
        }
		our_str->z--;
		our_str->len++;
	}
	if (our_str->convert_flags[1] == '+')
    {
		ft_putchar('+');
		our_str->len++;
	}
    return (our_str);
}

t_printf        *ft_positive_width5(t_printf *our_str)
{
    if (our_str->precision == 0)
    {
        our_str->z = our_str->z - our_str->ranks;
    }
	if (our_str->convert_flags[1] == '+')
	{
	    our_str->z--;
		ft_putchar('+');
		our_str->len++;
	}
	while (our_str->z > 0)
	{
        if (our_str->convert_flags[3] == '0')
        {
		    ft_putchar('0');
        }
        if (our_str->convert_flags[3] != '0')
        {
            ft_putchar(' ');
        }
		our_str->z--;
		our_str->len++;
	}
    return (our_str);
}