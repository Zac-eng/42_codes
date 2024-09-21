/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:26:34 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/05/27 15:56:35 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_set(int c);

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*s_head;

	index = 0;
	s_head = (char *) s;
	c = c_set(c);
	while (s[index] != c && s[index] != '\0')
		index += 1;
	if (s[index] == '\0' && c != '\0')
		return (NULL);
	return (s_head + index);
}

static int	c_set(int c)
{
	c = c % 128;
	if (c < 0)
		c = 128 + c;
	return (c);
}
