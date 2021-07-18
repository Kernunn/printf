/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:32:02 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/03 21:35:07 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_tolower(int c) {
  if (c >= 'A' && c <= 'Z')
	return (c - 'A' + 'a');
  return (c);
}
