/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 11:43:57 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/04 10:08:33 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			k;
	unsigned char	*s1;
	unsigned char	*s2;

	if (!dest && !src)
		return (dest);
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	k = 0;
	while (k < n)
	{
		*s1++ = *s2++;
		k++;
	}
	return (dest);
}
