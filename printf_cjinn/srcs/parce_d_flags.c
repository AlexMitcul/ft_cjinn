/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_d_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstreet <fstreet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 00:00:05 by alisher           #+#    #+#             */
/*   Updated: 2019/12/14 16:44:50 by fstreet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_printf        *ft_check_numb1(t_printf *our_str)
{
    our_str->check_prec = 0;
	our_str->str_d = ft_universal_itoa(our_str->numb);
	our_str->ranks = ft_strlen(our_str->str_d);
	our_str->P_R = our_str->precision - our_str->ranks;
    return (our_str);
}


t_printf        *ft_check_numb_P_R(t_printf *our_str)
{
    our_str->j = 0;
    if (our_str->P_R > 0)
	    {
		    our_str->s_prec = (char *)malloc(sizeof(char) * our_str->P_R);
		    while (our_str->P_R > 0)
		    {
			    our_str->s_prec[our_str->j] = '0';
			    our_str->P_R--;
			    our_str->j++;
		    }
        our_str->check_prec = 1;
	}
    return (our_str);
}

t_printf        *ft_base_display(t_printf *our_str)
{
	if (our_str->convert_flags[0] == '-')
    {

		ft_ddisplay_htdiw(our_str);
    }
	while (our_str->str_d[our_str->i1] != '\0')
	{
		if (our_str->check_prec != 0)
		{

            our_str->W_P = our_str->width - our_str->precision;

			while (our_str->j > 0)
			{
				ft_putchar(our_str->s_prec[our_str->j - 1]);
				our_str->j--;
				our_str->len++;
			}
			ft_strdel(&our_str->s_prec);
		}
        if (our_str->numb == 0)
        {
            if (our_str->convert_flags[0] == '\0' && our_str->convert_flags[1] == '\0')
            {
                if (our_str->width == 0 || our_str->precision == 0)
                {
                    our_str->zero = 1;
                }
            }
        }
        if (our_str->zero == 0)
        {
		    ft_putchar(our_str->str_d[our_str->i1]);
        }
        if (our_str->zero == 1)
        {
            if (our_str->width != 0)
                our_str->len++;
            if (our_str->width != 0)
                ft_putchar(' ');
        }
		if (our_str->zero == 0)
            our_str->len++;
		our_str->i1++;
	}
	if (our_str->convert_flags[0] == '-')
    {
    	ft_display_htdiw(our_str);
    }
    return (our_str);
}

t_printf		*ft_display_width(t_printf *our_str)
{
	if (our_str->width == 0)
	{
		if (our_str->negative_d == '-')
			{
				ft_putchar('-');
				our_str->len++;
				our_str->negative_d = '\0';
			}
		else if (our_str->convert_flags[1] == '+')
			{
				ft_putchar('+');
				our_str->len++;
			}
		else if (our_str->convert_flags[2] == ' ')
			{
				ft_putchar(' ');
				our_str->len++;
			}
	}
	ft_positive_width(our_str);
	return (our_str);
}
