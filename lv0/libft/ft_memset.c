/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:41:33 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/05/26 15:50:58 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			filled_count;
	unsigned char	*ret_str;
	unsigned char	for_filling;

	ret_str = b;
	filled_count = 0;
	for_filling = c;
	while (filled_count < len)
	{
		ret_str[filled_count] = for_filling;
		filled_count += 1;
	}
	return (ret_str);
}
