/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:24:47 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/08 14:53:13 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_local;
	unsigned char	*s2_local;
	size_t			cmp_count;

	cmp_count = 0;
	if (n == 0)
		return (0);
	s1_local = (unsigned char *)s1;
	s2_local = (unsigned char *)s2;
	while (*s1_local != '\0' && *s2_local != '\0' && cmp_count < n - 1)
	{
		if (*s1_local != *s2_local)
			return (*s1_local - *s2_local);
		else
		{
			s1_local += 1;
			s2_local += 1;
			cmp_count += 1;
		}
	}
	return (*s1_local - *s2_local);
}
