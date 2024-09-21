/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:37:18 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/08 15:25:24 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*processed_str;
	int		s_len;
	int		index;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	index = 0;
	processed_str = (char *)malloc(sizeof(char) * s_len + 1);
	if (processed_str == NULL)
		return (NULL);
	while (index < s_len)
	{
		processed_str[index] = (*f)(index, s[index]);
		index += 1;
	}
	processed_str[index] = '\0';
	return (processed_str);
}
