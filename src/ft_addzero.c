/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:38:50 by gmorros           #+#    #+#             */
/*   Updated: 2020/06/04 12:19:21 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
int ft_addzero(t_format *frm, int len_n) {
  int sign;
  int count1;
  int count2;

  count2 = 0;
  count1 = ft_addspace(frm, len_n);
  sign = ft_print_sign(frm, 0);
  if (frm->prec_bool && frm->precision)
	while (count2 < frm->precision + frm->minus - len_n) {
	  write(1, "0", 1);
	  count2++;
	}
  else if (frm->zero && !frm->l_align) {
	//	while (count2 < (frm->width > frm->precision ?
	//				frm->width : frm->precision) - len_n - sign)
	while (count2 < (frm->width ? frm->width : 0) - len_n - sign) {
	  write(1, "0", 1);
	  count2++;
	}
  }
  return (count1 + count2 + sign);
}

int ft_addspace(t_format *frm, int len_n) {
  int i;
  int sign;

  sign = 0;
  i = 0;
  if (frm->l_align || ((frm->prec_bool ? !frm->precision : 1) && frm->zero))
	return (0);
  if (frm->sharp && !frm->nul)
	sign = 2;
  if ((frm->space || frm->plus) && !frm->nul)
	sign = 1;
  if (frm->minus && !frm->nul)
	sign = 0;
  while (i < frm->width - sign - ((frm->prec_bool && (len_n < frm->precision
	  + frm->minus)) ? frm->precision + frm->minus : len_n)) {
	write(1, " ", 1);
	i++;
  }
  return (i);
}

int ft_adr_null(t_format *frm) {
  int count;

  count = 0;
  if (frm->prec_bool && frm->precision > 6)
	frm->precision = 6;
  if (frm->l_align) {
	write(1, "(null)", (frm->prec_bool ? frm->precision : 6));
	while (count++ < frm->width - (frm->prec_bool ? frm->precision : 6))
	  write(1, " ", 1);
  } else {
	while (count++ < frm->width - (frm->prec_bool ? frm->precision : 6))
	  write(1, " ", 1);
	write(1, "(null)", (frm->prec_bool ? frm->precision : 6));
  }
  count--;
  return ((frm->prec_bool ? frm->precision : 6) + count);
}

int ft_addspace_double(t_format *frm, int len_to_dot) {
  int count;
  int dot;
  int sign;

  sign = 0;
  if ((frm->space || frm->plus) && !frm->minus)
	sign = 1;
  dot = (!(frm->prec_bool && !frm->precision && !frm->sharp));
  count = 0;
  if (!frm->zero) {
	while (count < frm->width - len_to_dot -
		(frm->prec_bool ? frm->precision + dot : 6 + dot) - sign) {
	  write(1, " ", 1);
	  count++;
	}
  }
  return (count);
}

int ft_addzero_double(t_format *frm, int len_to_dot) {
  int count;
  int dot;
  int sign;

  dot = (!(frm->prec_bool && !frm->precision && !frm->sharp));
  count = 0;
  sign = ft_print_sign(frm, 1);
  if (frm->zero && !frm->l_align) {
	while (count++ < frm->width - (frm->prec_bool ? frm->precision
		+ dot : 6 + dot) - len_to_dot - sign)
	  write(1, "0", 1);
	count--;
  }
  return (count + sign + frm->minus);
}
