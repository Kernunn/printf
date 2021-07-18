/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:09:02 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/11 20:14:04 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void ft_putnbr(char *ans, size_t n, char *base, size_t n_base) {
  if (n >= n_base)
	ft_putnbr(ans - 1, n / n_base, base, n_base);
  ans[0] = base[n % n_base];
}

char *ft_itoa_unsigned(unsigned int n, char *base) {
  size_t count;
  unsigned int number;
  char *ans;
  int n_base;

  count = (n == 0 ? 1 : 0);
  number = n;
  n_base = ft_strlen(base);
  if (n_base < 2)
	return (0);
  while (n != 0) {
	count++;
	n = n / n_base;
  }
  ans = (char *) ft_calloc(sizeof(char), count + 1);
  if (!ans)
	return (NULL);
  ft_putnbr(ans + count - 1, number, base, n_base);
  return (ans);
}

char *ft_itoa_ull(unsigned long long n, char *base) {
  size_t count;
  unsigned long long number;
  char *ans;
  int n_base;

  count = (n == 0 ? 1 : 0);
  number = n;
  n_base = ft_strlen(base);
  if (n_base < 2)
	return (0);
  while (n != 0) {
	count++;
	n = n / n_base;
  }
  ans = (char *) ft_calloc(sizeof(char), count + 1);
  if (!ans)
	return (NULL);
  ft_putnbr(ans + count - 1, number, base, n_base);
  return (ans);
}
