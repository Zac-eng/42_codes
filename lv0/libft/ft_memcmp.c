/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:10:15 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/05/28 14:18:51 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*casted_str1;
	unsigned char	*casted_str2;
	size_t			compared_count;

	if (s1 == NULL && s2 == NULL)
		return (0);
	compared_count = 0;
	casted_str1 = (unsigned char *) s1;
	casted_str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (compared_count < n)
	{
		if (casted_str1[compared_count] != casted_str2[compared_count])
			return (casted_str1[compared_count] - casted_str2[compared_count]);
		else
			compared_count += 1;
	}
	return (0);
}
