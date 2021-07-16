/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 19:02:46 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/04 09:23:02 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle,
		size_t len)
{
	size_t		i;
	const char	*stop;

	stop = haystack + len;
	if (!needle[0])
		return ((char *)haystack);
	while (*haystack && haystack < stop)
	{
		i = 0;
		while (*haystack == needle[i] && *haystack && *needle
				&& i < len && haystack < stop)
		{
			haystack++;
			i++;
		}
		if (!needle[i])
			return ((char *)haystack - i);
		if (i == len)
			return (NULL);
		haystack = haystack - i + 1;
	}
	return (NULL);
}
