/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:49:58 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/05 18:05:09 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size) {
  void *ans;

  if (nmemb > SIZE_MAX / size)
	return (NULL);
  ans = malloc(size * nmemb);
  if (ans)
	return (ft_memset(ans, '\0', size * nmemb));
  return (NULL);
}
