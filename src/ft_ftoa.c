/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:27:43 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/14 13:05:12 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void ft_putnbr(char *tmp, long double n_double) {
  int n_int;
  int count;

  count = 0;
  n_int = 0;
  while (n_double != 0 && count < 22) {
	n_double *= 10;
	n_int = n_double;
	tmp[count++] = (n_int > 0 ? n_int : -n_int) + '0';
	n_double = n_double - n_int;
  }
  while (count < 6)
	tmp[count++] = '0';
  tmp[count] = '\0';
}

char *ft_ftoa(double n) {
  char *tmp1;
  char *tmp2;
  char *ans;

  if (n != n)
	return (ft_strdup("nan"));
  if (n != 0 && n * 2 == n) {
	if (n > 0)
	  return (ft_strdup("+inf"));
	else
	  return (ft_strdup("-inf"));
  }
  tmp2 = (char *) malloc(sizeof(char) * 40);
  if (!tmp2)
	return (NULL);
  tmp1 = ft_itoa_ll((long long) (n));
  tmp2[0] = '.';
  ft_putnbr(tmp2 + 1, (long double) (n - (long long) n));
  ans = ft_strjoin(tmp1, tmp2);
  if (n < 0 && *tmp1 == '0')
	ans = ft_strjoin("-", ans);
  free(tmp1);
  free(tmp2);
  return (ans);
}
