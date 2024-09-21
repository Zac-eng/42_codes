/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:49:25 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/11 11:03:34 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflows(size_t count, size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*allocated_ptr;
	size_t			allocated_num;

	allocated_num = 0;
	if (overflows(count, size) == 1)
		return (NULL);
	allocated_ptr = (unsigned char *)malloc(size * count);
	if (allocated_ptr == NULL)
		return (NULL);
	if (size * count == 0)
	{
		*allocated_ptr = 0;
		return (allocated_ptr);
	}
	while (allocated_num < size * count)
	{
		allocated_ptr[allocated_num] = 0;
		allocated_num += 1;
	}
	return (allocated_ptr);
}

static int	overflows(size_t count, size_t size)
{
	size_t	current_count;

	current_count = 0;
	while (size > 0)
	{
		if (current_count > current_count + count)
			return (1);
		else
			current_count += count;
		size -= 1;
	}
	return (0);
}
