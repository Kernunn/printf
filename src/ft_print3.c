/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:18:13 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/13 11:27:47 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int print_float_g(char *num, int len_to_dot, t_format *frm, va_list ap) {
  int change;
  int len_after_dot;

  ft_digit(num, len_to_dot, frm);
  len_after_dot = (frm->prec_bool ? frm->precision - len_to_dot
								  : 6 - len_to_dot);
  change = len_after_dot;
  frm->prec_bool = 1;
  while (num[len_after_dot + len_to_dot] == '0')
	len_after_dot--;
  if (change - len_after_dot == 0 && *num == '0')
	len_after_dot++;
  frm->precision = len_after_dot;
  free(num);
  return (ft_print_float(ap, frm));
}

int ft_print_g(va_list ap, t_format *frm) {
  int len_to_dot;
  char *num;
  va_list aq;

  va_copy(aq, ap);
  num = ft_ftoa(va_arg(aq, double));
  va_end(aq);
  len_to_dot = ft_strchr(num, '.') - num;
  if (len_to_dot > (frm->prec_bool ? frm->precision : 6)) {
	free(num);
	frm->precision = (frm->prec_bool ? frm->precision - 1 : 5);
	if (frm->precision < 0)
	  frm->precision = 0;
	frm->prec_bool = 1;
	return (ft_print_exp(ap, frm));
  }
  return (print_float_g(num, len_to_dot, frm, ap));
}

int ft_record(va_list ap, t_format *frm) {
  signed int *p;

  p = va_arg(ap, signed int *);
  *p = frm->count;
  return (0);
}

int ft_print_sign(t_format *frm, int n_double) {
  if ((frm->prec_bool ? frm->precision : 1) ||
	  (frm->plus || frm->space || n_double)) {
	if (frm->minus) {
	  write(1, "-", 1);
	  return (0);
	}
	if (frm->plus || frm->space) {
	  write(1, (frm->plus ? "+" : " "), 1);
	  return (1);
	}
	if (frm->sharp && !frm->nul && !n_double) {
	  if (!ft_strncmp(frm->base_number, "0123456789abcdef", 16))
		write(1, "0x", 2);
	  else
		write(1, "0X", 2);
	  return (2);
	}
  }
  return (0);
}

int ft_print_dot(t_format *frm) {
  if ((frm->prec_bool ? !frm->precision : 0) && frm->sharp) {
	write(1, ".", 1);
	return (1);
  }
  return (0);
}
