/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 13:54:52 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/04 09:08:37 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t k;

	k = 0;
	while (((unsigned char *)s1)[k] == ((unsigned char *)s2)[k]
			&& k < n)
		k++;
	if (k == n)
		return (0);
	return ((int)(((unsigned char *)s1)[k] - ((unsigned char *)s2)[k]));
}
