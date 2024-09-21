/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:27:32 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/08 15:21:38 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	limited_cpy(char *dst, char *src, size_t limit);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr_ptr;
	char	*start_ptr;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen((char *)s);
	start_ptr = (char *)s + start;
	substr_ptr = (char *)malloc(len + 1);
	if (substr_ptr == NULL)
		return (NULL);
	if (start >= s_len)
		return (substr_ptr);
	limited_cpy(substr_ptr, start_ptr, len);
	return (substr_ptr);
}

static void	limited_cpy(char *dst, char *src, size_t limit)
{
	while (*src != '\0' && limit > 0)
	{
		*dst = *src;
		dst += 1;
		src += 1;
		limit -= 1;
	}
	*dst = '\0';
}
