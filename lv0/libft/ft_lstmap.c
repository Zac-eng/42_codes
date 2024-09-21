/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:42:46 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/11 11:14:55 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*struct_list;
	t_list	*new_elem;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	struct_list = NULL;
	while (lst)
	{
		new_elem = ft_lstnew((*f)(lst->content));
		if (new_elem == NULL)
		{
			ft_lstclear(&struct_list, del);
			return (NULL);
		}
		ft_lstadd_back(&struct_list, new_elem);
		lst = lst->next;
	}
	return (struct_list);
}
