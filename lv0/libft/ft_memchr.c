/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:58:36 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/08 11:17:23 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*current_ptr;
	unsigned char	target;
	size_t			checked_num;

	checked_num = 0;
	target = c;
	current_ptr = (unsigned char *) s;
	while (checked_num < n)
	{
		if (*current_ptr == target)
			return (current_ptr);
		current_ptr += 1;
		checked_num += 1;
	}
	return (NULL);
}
