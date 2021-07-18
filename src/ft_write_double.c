/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 10:29:36 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/13 11:13:10 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_digit(char *num, int len_to_dot, t_format *frm) {
  int len;
  int vume;

  len = len_to_dot + (frm->prec_bool ? frm->precision : 6) + 1;
  if (num[len] >= '5') {
	vume = 1;
	while (vume) {
	  if (len == len_to_dot)
		len--;
	  if (num[len - (len - 1 == len_to_dot ? 2 : 1)] != '9') {
		num[len - (len - 1 == len_to_dot ? 2 : 1)] += 1;
		vume = 0;
	  } else {
		num[len - (len - 1 == len_to_dot ? 2 : 1)] = '0';
		vume = 1;
	  }
	  len--;
	}
  }
}

int ft_write_double(char *num, t_format *frm, int len_to_dot) {
  int count;

  count = 0;
  ft_digit(num, len_to_dot, frm);
  if (!frm->prec_bool)
	write(1, num, len_to_dot + 7);
  else {
	write(1, num, len_to_dot);
	if (frm->precision) {
	  count = ft_strlen(num + len_to_dot + 1);
	  write(1, num + len_to_dot, 1 +
		  (frm->precision < count ? frm->precision : count));
	  while (count++ < frm->precision)
		write(1, "0", 1);
	  count = frm->precision + 1;
	}
  }
  return (frm->prec_bool ? len_to_dot + count : len_to_dot + 7);
}

void ft_is_exp(char **num, int *degree, t_format *frm) {
  int count;

  count = 0;
  while (*(*num + frm->minus) == '0') {
	*(*num + frm->minus + 1) = *(*num + frm->minus + 2);
	*(*num + frm->minus + 2) = '.';
	*degree = *degree - 1;
	*num = *num + 1;
  }
  if (frm->minus)
	**num = '-';
  while (*(*num + frm->minus + count) != '.')
	count++;
  while (count > 1) {
	*(*num + frm->minus + count) = *(*num + frm->minus + count - 1);
	*(*num + frm->minus + count-- - 1) = '.';
	*degree = *degree + 1;
  }
}

int ft_write_exp(t_format *frm, int count, int degree) {
  int i;

  i = 0;
  write(1, "e", 1);
  if (degree < 0)
	write(1, "-", 1);
  else
	write(1, "+", 1);
  if (degree < 10)
	write(1, "0", 1);
  ft_putnbr_fd((degree > 0 ? degree : -degree), 1);
  if (frm->l_align) {
	while (count++ < frm->width - 4) {
	  write(1, " ", 1);
	  i++;
	}
  }
  return (4 + i);
}
