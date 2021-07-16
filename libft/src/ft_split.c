/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:05:07 by gmorros           #+#    #+#             */
/*   Updated: 2020/09/27 11:08:07 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_strcpy1(char *dest, char const *s, char c)
{
	while (!(*s == c) && *s)
		*dest++ = *s++;
	*dest = '\0';
	return (s);
}

static int			ft_strlen1(char const *s, char c)
{
	int count;

	count = 0;
	while (!(*s == c) && *s)
	{
		s++;
		count++;
	}
	return (count);
}

static size_t		ft_wcount(char const *s, char c)
{
	size_t nword;

	nword = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			nword++;
		while (!(*s == c) && *s)
			s++;
	}
	return (nword);
}

static char			**ft_clear(char **mas, size_t count)
{
	while (count)
		free(mas[count--]);
	free(mas);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	size_t	i;
	char	**mas;
	size_t	wordcount;

	if (!s)
		return (NULL);
	i = 0;
	wordcount = ft_wcount(s, c);
	mas = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (mas)
	{
		while (i < wordcount)
		{
			while (*s == c)
				s++;
			if ((mas[i] = (char *)malloc(sizeof(char) * ft_strlen1(s, c) + 1)))
				s = ft_strcpy1(mas[i], s, c);
			else
				return (ft_clear(mas, i - 1));
			i++;
		}
		mas[i] = NULL;
	}
	return (mas);
}
