/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 10:37:03 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/14 12:16:21 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_print_percent(va_list ap, t_format *frm)
{
	int	count;

	if (ap)
		count = 0;
	count = 0;
	if (frm->l_align)
	{
		write(1, "%", 1);
		while (count++ + 1 < frm->width)
			write(1, " ", 1);
	}
	else
	{
		while (count++ + 1 < frm->width)
			write(1, (frm->zero ? "0" : " "), 1);
		write(1, "%", 1);
	}
	return (frm->width > 0 ? frm->width : 1);
}

int			ft_is_nan(char *num, t_format *frm)
{
	int count;

	count = 0;
	if (frm->l_align)
	{
		write(1, num, 3);
		while (count++ < frm->width - 3)
			write(1, " ", 1);
	}
	else
	{
		while (count++ < frm->width - 3)
			write(1, " ", 1);
		write(1, num, 3);
	}
	free(num);
	return (frm->width > 3 ? frm->width : 3);
}

static int	ft_printf_inf(char *num, t_format *frm, int plus, int sign)
{
	int count;

	count = 0;
	if (frm->l_align)
	{
		if (sign)
			write(1, (frm->plus ? "+" : " "), 1);
		write(1, num + plus, 4 - plus);
		while (count++ < frm->width - 4 + plus - sign)
			write(1, " ", 1);
	}
	else
	{
		while (count++ < frm->width - 4 + plus - sign)
			write(1, " ", 1);
		if (sign)
			write(1, (frm->plus ? "+" : " "), 1);
		write(1, num + plus, 4 - plus);
	}
	count--;
	free(num);
	return (count + 4 - plus + sign);
}

int			ft_is_inf(char *num, t_format *frm)
{
	int	plus;
	int	sign;

	sign = 0;
	plus = *num == '+' ? 1 : 0;
	if ((frm->plus || frm->space) && *num != '-')
		sign = 1;
	return (ft_printf_inf(num, frm, plus, sign));
}
