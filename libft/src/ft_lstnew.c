/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:27:32 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/01 11:30:11 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content) {
  t_list *new;

  new = (t_list *) malloc(sizeof(t_list));
  if (new) {
	new->content = content;
	new->next = NULL;
  }
  return (new);
}
