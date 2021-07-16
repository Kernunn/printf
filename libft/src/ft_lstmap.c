/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:59:34 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/03 23:34:00 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_clear(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new && f && lst)
	{
		tmp = new;
		while (lst)
		{
			tmp->content = f(lst->content);
			if (lst->next)
			{
				tmp->next = (t_list *)malloc(sizeof(t_list));
				if (!(tmp->next))
					return (ft_clear(&new, del));
			}
			else
				tmp->next = NULL;
			tmp = tmp->next;
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
