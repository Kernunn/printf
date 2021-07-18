/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:07:29 by gmorros           #+#    #+#             */
/*   Updated: 2020/06/04 12:11:56 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_print_char(va_list ap, t_format *frm) {
  int count;

  count = frm->width;
  if (frm->l_align) {
	ft_putchar_fd(((char) va_arg(ap, int)), 1);
	while (count-- > 1)
	  write(1, " ", 1);
  } else {
	while (count-- > 1)
	  write(1, " ", 1);
	ft_putchar_fd(((char) va_arg(ap, int)), 1);
  }
  return (frm->width ? frm->width : 1);
}

int ft_print_str(va_list ap, t_format *frm) {
  char *str;
  int len_s;
  int count;

  count = 0;
  str = va_arg(ap, char *);
  if (!str)
	return (ft_adr_null(frm));
  len_s = (int) ft_strlen(str);
  if (frm->prec_bool && len_s > frm->precision)
	len_s = frm->precision;
  if (frm->l_align) {
	write(1, str, len_s);
	while (len_s + count++ < frm->width)
	  write(1, " ", 1);
  } else {
	while (len_s + count++ < frm->width)
	  write(1, " ", 1);
	write(1, str, len_s);
  }
  return (frm->width > len_s ? frm->width : len_s);
}

int ft_print_adr(va_list ap, t_format *frm) {
  int count;
  char *adr;
  int len_adr;

  count = 0;
  adr = ft_itoa_ull(va_arg(ap, unsigned long int), frm->base_number);
  len_adr = ft_strlen(adr) + 2;
  if (frm->l_align) {
	write(1, "0x", 2);
	ft_putstr_fd(adr, 1);
	while (count++ + len_adr < frm->width)
	  write(1, " ", 1);
  } else {
	while (count++ + len_adr < frm->width)
	  write(1, " ", 1);
	write(1, "0x", 2);
	ft_putstr_fd(adr, 1);
  }
  free(adr);
  return (len_adr > frm->width ? len_adr : frm->width);
}

int ft_print_number(va_list ap, t_format *f) {
  int count;
  int len;
  char *num;

  count = 0;
  num = ft_size_signed(ap, f);
  len = (f->prec_bool && !f->precision && *num == '0') ? 0 : ft_strlen(num);
  f->minus = (*num == '-' ? 1 : 0);
  if (f->l_align) {
	count = ft_addzero(f, len);
	write(1, num + f->minus, len - f->minus);
	while (len + count++ < f->width)
	  write(1, " ", 1);
	count--;
  } else {
	count = ft_addzero(f, len);
	if ((f->prec_bool ? f->precision : 1) || *num != '0')
	  write(1, num + f->minus, len - f->minus);
  }
  free(num);
  return (len + count);
}

int ft_print_unsigned(va_list ap, t_format *f) {
  int count;
  int len;
  char *num;

  count = 0;
  ft_changeflag(f);
  num = ft_size_unsigned(ap, f);
  f->nul = (*num == '0' ? 1 : 0);
  len = (f->prec_bool && !f->precision && *num == '0') ? 0 : ft_strlen(num);
  if (f->l_align) {
	count = ft_addzero(f, len);
	write(1, num, len);
	while (len + count++ < f->width)
	  write(1, " ", 1);
	count--;
  } else {
	count += ft_addzero(f, len);
	if ((f->prec_bool ? f->precision : 1) || *num != '0')
	  write(1, num, len);
  }
  free(num);
  return (len + count);
}
