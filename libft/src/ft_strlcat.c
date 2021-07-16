/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:14:40 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/04 09:11:30 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (dest[i] && i < size)
		i++;
	if (size != 0 && i != size)
	{
		while (i < size - 1 && *src)
			dest[i++] = *src++;
		dest[i] = '\0';
	}
	while (*src++)
		i++;
	return (i);
}
