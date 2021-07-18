/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:38:28 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/02 14:59:16 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int checkset(char c, char const *set) {
  while (*set) {
	if (c == *set)
	  return (1);
	set++;
  }
  return (0);
}

static void trim(char const *s1, char const *set, char *new, int size) {
  int i;

  i = 0;
  if (size != 0) {
	while (*s1 && checkset(*s1, set))
	  s1++;
	while (i != size) {
	  new[i] = *s1;
	  i++;
	  s1++;
	}
  }
  new[i] = '\0';
}

static int countelem(char const *s1, char const *set) {
  size_t i;
  size_t k;

  i = 0;
  k = 0;
  while (s1[i] && checkset(s1[i], set)) {
	i++;
	k++;
  }
  while (s1[i])
	i++;
  while (--i != 0 && s1[i] && checkset(s1[i], set));
  if (i == 0)
	return (0);
  return (i - k + 1);
}

char *ft_strtrim(char const *s1, char const *set) {
  int i;
  char *new;

  if (!(s1 && set))
	return (NULL);
  i = countelem(s1, set);
  new = (char *) malloc(sizeof(char) * i + 1);
  if (new) {
	trim(s1, set, new, i);
	return (new);
  }
  return (NULL);
}
