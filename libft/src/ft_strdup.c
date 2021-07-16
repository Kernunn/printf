/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:37:13 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/04 09:27:44 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	if ((dup = (char *)malloc(sizeof(char) * len + 1)))
		if (ft_strlcpy(dup, s, len + 1) == len)
			return (dup);
	return (NULL);
}
