/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:13:40 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/06 17:24:43 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret_ptr;
	char	*s1_local;
	int		s1_len;

	s1_local = (char *)s1;
	s1_len = ft_strlen(s1_local);
	ret_ptr = (char *)malloc(sizeof(char) * s1_len + 1);
	if (ret_ptr == NULL)
		return (NULL);
	ft_strlcpy(ret_ptr, s1_local, s1_len + 1);
	return (ret_ptr);
}
