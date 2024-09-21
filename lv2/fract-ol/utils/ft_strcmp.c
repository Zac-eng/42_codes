/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:16:46 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/31 20:30:39 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_strcmp(char *lhs, char *rhs)
{
	if (lhs == NULL || rhs == NULL)
		return (-1);
	while (*lhs != '\0' && *rhs != '\0')
	{
		if (*lhs != *rhs)
			return (0);
		lhs += 1;
		rhs += 1;
	}
	if (*lhs != '\0' || *rhs != '\0')
		return (0);
	return (1);
}
