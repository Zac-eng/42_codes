/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:38:39 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/05/28 13:38:22 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dtsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	left_mem;
	size_t	cated_count;

	src_len = ft_strlen(src);
	if (dtsize == 0)
		return (dtsize + src_len);
	dst_len = ft_strlen(dst);
	left_mem = dtsize - dst_len;
	cated_count = 0;
	if (dtsize <= dst_len)
		return (dtsize + src_len);
	while (cated_count < left_mem - 1 && src[cated_count] != '\0')
	{
		dst[dst_len + cated_count] = src[cated_count];
		cated_count += 1;
	}
	dst[dst_len + cated_count] = '\0';
	return (dst_len + src_len);
}
