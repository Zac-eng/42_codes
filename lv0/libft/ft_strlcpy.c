/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:10:38 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/05/27 14:36:27 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dtsize)
{
	char		*dst_local;
	size_t		copied_count;
	size_t		src_len;

	src_len = 0;
	copied_count = 0;
	dst_local = dst;
	while (src[src_len] != '\0')
		src_len += 1;
	if (dtsize == 0)
		return (src_len);
	while (copied_count < dtsize - 1 && src[copied_count] != '\0')
	{
		dst_local[copied_count] = src[copied_count];
		copied_count += 1;
	}
	dst_local[copied_count] = '\0';
	return (src_len);
}
