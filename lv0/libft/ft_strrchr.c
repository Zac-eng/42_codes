/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:59:20 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/05/27 16:22:54 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_set(int c);

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	int		current_last_index;
	char	*s_head;

	index = 0;
	current_last_index = 0;
	s_head = (char *) s;
	c = c_set(c);
	while (s[index] != '\0')
	{
		if (s[index] == c)
			current_last_index = index;
		index += 1;
	}
	if (s[index] == c)
		current_last_index = index;
	if (current_last_index == 0 && s[current_last_index] != c)
		return (NULL);
	return (s_head + current_last_index);
}

static int	c_set(int c)
{
	c = c % 128;
	if (c < 0)
		c = 128 + c;
	return (c);
}
