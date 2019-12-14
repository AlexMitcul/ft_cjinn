/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstreet <fstreet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:59:43 by cjinn             #+#    #+#             */
/*   Updated: 2019/12/14 16:38:38 by fstreet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*input_data(t_printf *our_str)
{
	our_str->copy_str = (char*)our_str->str;
	our_str->ccopy_str = (char*)our_str->str;
	our_str->len = 0;
	our_str->i = 0;
	our_str->specifier = "cspdiouxX";
	our_str->flags = "-+ 0#";
	our_str->following_flags = "lh";
	return (our_str);
}

int			ft_printf(const char *str, ...)
{
	t_printf	*our_str;

	if (!(our_str = (t_printf*)malloc(sizeof(t_printf))))
		return (-1);
	our_str->str = str;
	our_str = input_data(our_str);
	if (our_str)
	{
		va_start(our_str->arguments, str);
		our_str->len = str_counter(our_str);
		va_end(our_str->arguments);
	}
	//free(our_str->s_prec);
	free(our_str);
	return (our_str->len);
}
