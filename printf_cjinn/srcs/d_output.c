/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_output.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstreet <fstreet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:43:39 by cjinn             #+#    #+#             */
/*   Updated: 2019/12/14 16:38:33 by fstreet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	conversion_numb(t_printf *our_str)
{
	intmax_t	numb;

	if (ft_strcmp(our_str->follow_flag, "hh") == 0)
		numb = (signed char)(va_arg(our_str->arguments, int));
	else if (ft_strcmp(our_str->follow_flag, "h") == 0)
		numb = (short)(va_arg(our_str->arguments, int));
	else if (ft_strcmp(our_str->follow_flag, "ll") == 0)
		numb = (long long)(va_arg(our_str->arguments, long long int));
	else if (ft_strcmp(our_str->follow_flag, "l") == 0)
		numb = (long)(va_arg(our_str->arguments, long int));
	else
		numb = (int)(va_arg(our_str->arguments, int));
	numb = (intmax_t)numb;
	if (numb < 0)
	{
		our_str->negative_d = '-';
	}
	return (numb);
}

t_printf		*ft_positive_width(t_printf *our_str)
{
	our_str->z = 0;
	if (our_str->width > 0)
	{
		ft_positive_width1(our_str);
	}
	our_str->negative_d = '\0';
	return (our_str);
}

t_printf		*ft_display_htdiw(t_printf *our_str)
{
	if (our_str->width > 0)
	{
		our_str->z = our_str->width - our_str->precision;
		if (our_str->convert_flags[1] == '+')
			our_str->z--;
		if (our_str->width == 0 || our_str->precision == 0)
		{
			our_str->z = our_str->z - our_str->ranks;
		}
		if (our_str->negative_d == '-')
		{
			our_str->z = our_str->width - our_str->ranks - our_str->precision - 1;
		}
		while (our_str->z > 0)
		{
			ft_putchar(' ');
			our_str->z--;
			our_str->len++;
		}
	}
	return (our_str);
}

t_printf 		*ft_ddisplay_htdiw(t_printf *our_str)
{
	if (our_str->convert_flags[1] == '+')
	{
		ft_putchar('+');
		our_str->len++;
	}
	if (our_str->negative_d == '-')
	{
		ft_putchar('-');
		our_str->len++;
	}
	return(our_str);
}

t_printf	*d_output(t_printf *our_str)
{
	our_str->i1 = 0;
	our_str->numb = conversion_numb(our_str);
	ft_check_numb1(our_str);
	ft_check_numb_P_R(our_str);
	if (our_str->precision != 0)
		our_str->convert_flags[3] = '\0';
	if (our_str->convert_flags[0] != '-')
	{
		ft_display_width(our_str);
	}
	if (our_str->numb == -9223372036854775807 - 1)
	{
			ft_putstr("9223372036854775808");
			our_str->len += 19;
	}
	else
	{
		ft_base_display(our_str);
	}
	free(our_str->str_d);
	return(our_str);
}
