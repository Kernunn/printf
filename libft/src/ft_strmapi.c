/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:41:00 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/03 21:25:10 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*map;

	if (!s)
		return (NULL);
	i = 0;
	map = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (map)
	{
		while (*s)
		{
			map[i] = f(i, *s);
			s++;
			i++;
		}
		map[i] = '\0';
		return (map);
	}
	return (NULL);
}
