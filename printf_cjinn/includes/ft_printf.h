/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisher <alisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:53:42 by cjinn             #+#    #+#             */
/*   Updated: 2019/12/14 05:30:15 by alisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <ctype.h>
#include <stdio.h>
#include "libft.h"

typedef struct	s_printf
{
	const char	*str;
	char		*copy_str;
	char		*ccopy_str;
	int			len;
	int			i;
	int			j;
	int			i1;
	int			z;
	char		*flags;
	char		*specifier;
	char		*following_flags;
	char		specifier_flag;
	char		convert_flags[6];
	char		follow_flag[2];
	char		*str_d;
	int			width;
	int			precision;
	va_list		arguments;
	intmax_t	numb;
	int			ranks;
	char		negative_d;
	int			P_R;
	int			W_P;
	int			check_prec;
	char		*s_prec;
	int			zero;
}				t_printf;


typedef struct	s_check
{
	const char *check_str;
}				t_check;


/* ft_printf */

int			ft_printf(const char *str, ...);

/* program_core */

int			str_counter(t_printf *our_str);

/* fill_structure_elements */

t_printf	*fill_pf_convert_flags(t_printf *our_str);
t_printf	*fill_pf_width(t_printf *our_str);
t_printf	*fill_pf_precision(t_printf *our_str);
t_printf	*fill_pf_following_flags(t_printf *our_str);
t_printf	*fill_pf_specifier(t_printf *our_str);

/* display different flags */

t_printf		*d_output(t_printf *our_str);
char			*ft_universal_itoa(long long int n);
t_printf		*ft_display_width(t_printf *our_str);
t_printf		*ft_positive_width(t_printf *our_str);
t_printf		*ft_display_htdiw(t_printf *our_str);
t_printf 		*ft_ddisplay_htdiw(t_printf *our_str);
t_printf 		*ft_display_htdiw(t_printf *our_str);
t_printf		*ft_check_numb1(t_printf *our_str);
t_printf        *ft_check_numb_P_R(t_printf *our_str);
t_printf        *ft_base_display(t_printf *our_str);
t_printf        *ft_positive_width1(t_printf *our_str);
t_printf    	*ft_positive_width2(t_printf *our_str);
t_printf    	*ft_positive_width3(t_printf *our_str);
t_printf        *ft_positive_width4(t_printf *our_str);
t_printf        *ft_positive_width5(t_printf *our_str);

#endif
