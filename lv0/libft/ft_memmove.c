/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:46:31 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/05/28 13:30:48 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpy_forward(unsigned char *dst, unsigned char *src, long len);
static void	cpy_reverse(unsigned char *dst, unsigned char *src, long len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			moved_num;
	size_t			byte_per_char;
	unsigned char	*dst_local;
	unsigned char	*src_local;
	long			char_num;

	if (dst == NULL && src == NULL)
		return (NULL);
	moved_num = 0;
	dst_local = (unsigned char *) dst;
	src_local = (unsigned char *) src;
	byte_per_char = sizeof(*src);
	char_num = len / byte_per_char;
	if ((dst_local > src_local) && dst_local - src_local < char_num)
		cpy_reverse(dst_local, src_local, char_num);
	else
		cpy_forward(dst_local, src_local, char_num);
	return (dst);
}

static void	cpy_forward(unsigned char *dst, unsigned char *src, long len)
{
	long	moved_num;

	moved_num = 0;
	while (moved_num < len)
	{
		*(dst + moved_num) = *(src + moved_num);
		moved_num += 1;
	}
}

static void	cpy_reverse(unsigned char *dst, unsigned char *src, long len)
{
	long	moved_num;

	moved_num = 0;
	while (moved_num < len)
	{
		*(dst + len - moved_num - 1) = *(src + len - moved_num - 1);
		moved_num += 1;
	}
}
