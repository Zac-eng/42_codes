/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:51:33 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/05/26 15:58:15 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ret_ptr;
	size_t	filled_count;

	ret_ptr = s;
	filled_count = 0;
	while (filled_count < n)
	{
		ret_ptr[filled_count] = 0;
		filled_count += 1;
	}
}
