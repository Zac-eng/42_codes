/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:58:57 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/11 11:16:47 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_local;
	unsigned char	*src_local;
	size_t			copied_count;

	if (dst == NULL && src == NULL)
		return (NULL);
	copied_count = 0;
	dst_local = dst;
	src_local = (unsigned char *)src;
	while (copied_count < n)
	{
		dst_local[copied_count] = src_local[copied_count];
		copied_count += 1;
	}
	return (dst);
}
