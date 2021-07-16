/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:42:12 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/03 19:22:17 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *begin;

	if (lst)
	{
		begin = *lst;
		if (begin)
		{
			while (begin->next)
				begin = begin->next;
			begin->next = new;
		}
		else
			*lst = new;
	}
}
