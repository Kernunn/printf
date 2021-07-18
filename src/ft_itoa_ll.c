/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 08:02:28 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/11 15:50:23 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void ft_putnbr(char *ans, long long n) {
  if (n > 9 || n < -9)
	ft_putnbr(ans - 1, n / 10);
  ans[0] = (n > 0 ? n % 10 : -(n % 10)) + '0';
}

char *ft_itoa_ll(long long n) {
  long long number;
  size_t count;
  char *ans;

  count = (n <= 0 ? 1 : 0);
  number = n;
  while (n != 0) {
	count++;
	n /= 10;
  }
  ans = (char *) ft_calloc(sizeof(char), count + 1);
  if (!ans)
	return (NULL);
  if (number < 0)
	ans[0] = '-';
  ft_putnbr(ans + count - 1, number);
  return (ans);
}
