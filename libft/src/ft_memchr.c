/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 13:44:10 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/03 19:42:34 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t k;

	k = 0;
	while (k < n && ((unsigned char *)s)[k] != (unsigned char)c)
		k++;
	if (k == n)
		return (NULL);
	return ((void *)s + k);
}
