/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:21:24 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/04 09:12:27 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t count;

	count = 0;
	while (s[count] && ((unsigned char *)s)[count] != (unsigned char)c)
		count++;
	if (s[count] || (unsigned char)c == '\0')
		return ((char *)s + count);
	else
		return (NULL);
}
