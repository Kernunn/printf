/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 12:43:25 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/04 09:05:39 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n && ((unsigned char *)src)[k] != (unsigned char)c)
	{
		((unsigned char *)dest)[k] = ((unsigned char *)src)[k];
		k++;
	}
	if (k == n)
		return (NULL);
	((unsigned char *)dest)[k] = ((unsigned char *)src)[k];
	return (dest + k + 1);
}
