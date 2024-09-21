/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:45:01 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/07 21:00:48 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	item_num;

	if (lst == NULL)
		return (0);
	item_num = 1;
	while (lst->next != NULL)
	{
		item_num += 1;
		lst = lst->next;
	}
	return (item_num);
}
