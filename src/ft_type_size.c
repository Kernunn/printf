/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 07:27:33 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/14 09:32:56 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *ft_size_signed(va_list ap, t_format *frm) {
  if (frm->l == 1)
	return (ft_itoa_ll((long) va_arg(ap, long)));
  if (frm->ll == 1)
	return (ft_itoa_ll((long long) va_arg(ap, long long)));
  if (frm->h == 1)
	return (ft_itoa((short int) va_arg(ap, int)));
  if (frm->hh == 1)
	return (ft_itoa((signed char) va_arg(ap, int)));
  return (ft_itoa((int) va_arg(ap, int)));
}

char *ft_size_unsigned(va_list ap, t_format *frm) {
  if (frm->l == 1) {
	return (ft_itoa_ull((unsigned long) va_arg(ap, unsigned long),
						frm->base_number));
  }
  if (frm->ll == 1) {
	return (ft_itoa_ull((unsigned long long) va_arg(ap, unsigned long long),
						frm->base_number));
  }
  if (frm->h == 1) {
	return (ft_itoa_unsigned((unsigned short int) va_arg(ap, unsigned int),
							 frm->base_number));
  }
  if (frm->hh == 1) {
	return (ft_itoa_unsigned((unsigned char) va_arg(ap, unsigned int),
							 frm->base_number));
  }
  return (ft_itoa_unsigned((unsigned int) va_arg(ap, unsigned int),
						   frm->base_number));
}

void ft_changeflag(t_format *frm) {
  frm->plus = 0;
  frm->space = 0;
  frm->minus = 0;
}

void ft_precision(char const **s, va_list ap, t_format *f) {
  f->prec_bool = 0;
  if (**s == '.') {
	f->precision = ft_atoi((*s)++ + 1);
	f->prec_bool = 1;
  }
  if (**s == '*') {
	f->precision = va_arg(ap, int);
	*s = *s + 1;
  }
  if (f->precision < 0)
	f->prec_bool = 0;
}
