/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:05:07 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/08 15:24:11 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1_local;
	char	*s2_local;
	char	*joined_ptr;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return ((char *)s1);
	s1_local = (char *)s1;
	s2_local = (char *)s2;
	s1_len = ft_strlen(s1_local);
	s2_len = ft_strlen(s2_local);
	joined_ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len));
	if (joined_ptr == NULL)
		return (NULL);
	ft_strlcpy(joined_ptr, s1_local, s1_len + 1);
	ft_strlcpy(joined_ptr + s1_len, s2_local, s2_len + 1);
	return (joined_ptr);
}
