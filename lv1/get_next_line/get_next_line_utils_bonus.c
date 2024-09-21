/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:37:58 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/07/01 12:03:54 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_line_len(char *buf)
{
	int	index;

	index = 0;
	if (buf == NULL)
		return (-1);
	while (buf[index] != '\0')
	{
		if (buf[index] == '\n')
		{
			index += 1;
			return (index);
		}
		else
			index += 1;
	}
	return (index);
}

void	memmove_left(char *memory, int displacement)
{
	int		mem_len;
	int		index;

	if (displacement == 0)
		return ;
	index = 0;
	mem_len = ft_strlen(memory);
	while (memory[index + displacement] != '\0')
	{
		memory[index] = memory[index + displacement];
		index += 1;
	}
	memory[index] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_ptr;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (joined_ptr == NULL)
		return (free_and_set_null(&s1));
	ft_strlcpy(joined_ptr, s1, s1_len + 1);
	ft_strlcpy(joined_ptr + s1_len, s2, s2_len + 1);
	free_and_set_null(&s1);
	return (joined_ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dtsize)
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

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*s != '\0')
	{
		length += 1;
		s += 1;
	}
	return (length);
}
