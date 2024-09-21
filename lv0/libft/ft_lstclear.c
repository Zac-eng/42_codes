/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:16:28 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/11 12:24:07 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		(*del)((*lst)->content);
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}
