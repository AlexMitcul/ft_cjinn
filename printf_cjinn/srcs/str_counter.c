/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisher <alisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:45:44 by cjinn             #+#    #+#             */
/*   Updated: 2019/12/14 05:29:04 by alisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*input_data2(t_printf *our_str)
{
	int j;
	j = 0;
	while (j < 6)
	{
		our_str->convert_flags[j] = '\0';
		j++;
	}
	our_str->specifier_flag = '\0';
	our_str->follow_flag[0] = '\0';
	our_str->follow_flag[1] = '\0';
	our_str->precision = 0;
	our_str->width = 0;
	return (our_str);
}

t_printf		*flag_output(t_printf *our_str)
{
	char *spec;

	spec = &our_str->specifier_flag;
	if (*spec == 'd' || *spec == 'i')
	{
		d_output(our_str);
	}
	return (our_str);
}

int				filling_basis(t_printf *our_str)
{
	our_str->i++;
	fill_pf_convert_flags(our_str);
	fill_pf_width(our_str);
	fill_pf_precision(our_str);
	fill_pf_following_flags(our_str);
	fill_pf_specifier(our_str);
	flag_output(our_str);
	return (our_str->len);
}

int				str_counter(t_printf *our_str)
{
	if (ft_strcmp(our_str->str, "%") == 0)
		return (0);
	while (our_str->copy_str[our_str->i] != '\0')
	{
		if (our_str->copy_str[our_str->i] == '%')
		{
			our_str = input_data2(our_str);
			filling_basis(our_str);
		}
		else
		{
			ft_putchar(our_str->copy_str[our_str->i]);
			our_str->len++;
		}
		our_str->i++;
	}
	return (our_str->len);
}
