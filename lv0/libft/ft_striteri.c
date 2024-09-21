/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:51:43 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/08 15:21:09 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	s_len;
	unsigned int	index;

	index = 0;
	if (s == NULL || f == NULL)
		return ;
	s_len = ft_strlen(s);
	while (index < s_len)
	{
		(*f)(index, s);
		s += 1;
		index += 1;
	}
}
