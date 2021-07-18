/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:09:02 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/11 08:01:25 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void ft_putnbr(char *ans, long int n) {
  if (n > 9)
	ft_putnbr(ans - 1, n / 10);
  ans[0] = n % 10 + '0';
}

char *ft_itoa(int n) {
  long long int number;
  size_t count;
  char *ans;

  count = (n <= 0 ? 1 : 0);
  number = n;
  while (n != 0) {
	count++;
	n = n / 10;
  }
  ans = (char *) ft_calloc(sizeof(char), count + 1);
  if (!ans)
	return (NULL);
  if (number < 0) {
	number = -number;
	ans[0] = '-';
  }
  ft_putnbr(ans + count - 1, number);
  return (ans);
}
