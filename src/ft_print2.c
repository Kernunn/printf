/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 10:41:02 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/14 11:29:36 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_write_float(char *num, t_format *f, int len_to_dot)
{
	int count;

	if (f->l_align)
	{
		count = ft_addzero_double(f, len_to_dot);
		count += ft_write_double(num + f->minus, f, len_to_dot - f->minus);
		count += ft_print_dot(f);
		while (count++ < f->width)
			write(1, " ", 1);
		count--;
	}
	else
	{
		count = ft_addspace_double(f, len_to_dot);
		count += ft_addzero_double(f, len_to_dot);
		count += ft_write_double(num + f->minus, f, len_to_dot - f->minus);
		count += ft_print_dot(f);
	}
	free(num);
	return (count);
}

int			ft_print_float(va_list ap, t_format *f)
{
	char	*num;
	int		len_to_dot;

	num = ft_ftoa(va_arg(ap, double));
	if (!ft_strncmp("nan", num, 3))
		return (ft_is_nan(num, f));
	if (!ft_strncmp(num + 1, "inf", 4))
		return (ft_is_inf(num, f));
	len_to_dot = ft_strchr(num, '.') - num;
	f->minus = (*num == '-' ? 1 : 0);
	return (ft_write_float(num, f, len_to_dot));
}

static	int	ft_check_nul(char *num, t_format *frm)
{
	frm->minus = (*num == '-' ? 1 : 0);
	while (*num == '0' || *num == '.')
		num++;
	if (!*num)
		return (1);
	return (0);
}

int			ft_print_exp(va_list ap, t_format *frm)
{
	char	*num;
	int		degree;
	int		count;

	degree = 0;
	num = ft_ftoa(va_arg(ap, double));
	if (!ft_check_nul(num, frm))
		ft_is_exp(&num, &degree, frm);
	if (frm->l_align)
	{
		count = ft_addzero_double(frm, 5);
		count += ft_write_double(num + frm->minus, frm, 1);
		count += ft_print_dot(frm);
		count += ft_write_exp(frm, count, degree);
	}
	else
	{
		count = ft_addspace_double(frm, 5);
		count += ft_addzero_double(frm, 5);
		count += ft_write_double(num + frm->minus, frm, 1);
		count += ft_print_dot(frm);
		count += ft_write_exp(frm, count, degree);
	}
	free(num + (degree < 0 ? degree : 0));
	return (count);
}
