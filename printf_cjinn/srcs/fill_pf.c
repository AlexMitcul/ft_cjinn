/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisher <alisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:08:30 by cjinn             #+#    #+#             */
/*   Updated: 2019/12/11 05:53:02 by alisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*fill_pf_convert_flags(t_printf *our_str)
{
	int	i;

	i = 0;
	while (our_str->flags[i] != '\0')
	{
		while (our_str->flags[i] == our_str->copy_str[our_str->i])
		{
			while (our_str->ccopy_str[our_str->i] == '-' && our_str->i++)
				our_str->convert_flags[0] = '-';
			while (our_str->ccopy_str[our_str->i] == '+' && our_str->i++)
				our_str->convert_flags[1] = '+';
			while (our_str->ccopy_str[our_str->i] == ' ' && our_str->i++)
				our_str->convert_flags[2] = ' ';
			while (our_str->ccopy_str[our_str->i] == '0' && our_str->i++)
				our_str->convert_flags[3] = '0';
			while (our_str->ccopy_str[our_str->i] == '#' && our_str->i++)
				our_str->convert_flags[4] = '#';
			i = 0;
		}
		i++;
	}
	return (our_str);
}

t_printf	*fill_pf_width(t_printf *our_str)
{
	while (our_str->ccopy_str[our_str->i] >= '0' && our_str->ccopy_str[our_str->i] <= '9')
	{
		our_str->width = our_str->width * 10;
		our_str->width = our_str->width + (our_str->ccopy_str[our_str->i] - '0');
		our_str->i++;
	}
	return(our_str);
}

t_printf	*fill_pf_precision(t_printf *our_str)
{
	while (our_str->ccopy_str[our_str->i] == '.')
	{
		our_str->i++;
		our_str->precision = 0;
	}
	while (our_str->ccopy_str[our_str->i] >= '0' && our_str->ccopy_str[our_str->i] <= '9')
	{
		our_str->precision = our_str->precision * 10;
		our_str->precision = our_str->precision + our_str->ccopy_str[our_str->i] - '0';
		our_str->i++;
	}
	return (our_str);
}

t_printf	*fill_pf_following_flags(t_printf *our_str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (our_str->following_flags[i] != '\0')
	{
		while (our_str->following_flags[i] == our_str->ccopy_str[our_str->i])
		{
			our_str->follow_flag[j] = our_str->ccopy_str[our_str->i];
			our_str->follow_flag[j + 1] = '\0';
			our_str->i++;
			j++;
		}
		i++;
	}
	return (our_str);
}

t_printf	*fill_pf_specifier(t_printf *our_str)
{
	int i;

	i = 0;
	while (our_str->specifier[i] != '\0')
	{
		if (our_str->specifier[i] == our_str->ccopy_str[our_str->i])
			our_str->specifier_flag = our_str->specifier[i];
		i++;
	}
	return (our_str);
}

