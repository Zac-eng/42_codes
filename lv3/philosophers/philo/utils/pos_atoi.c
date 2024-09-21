/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:08:50 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/11/22 12:38:00 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

static int	overflows(int current, char next);

int	pos_atoi(char *str)
{
	int	current_num;

	if (str == NULL)
		return (-1);
	current_num = 0;
	if (*str == '0')
	{
		if (*(str + 1) == '\0')
			return (0);
		else
			return (-1);
	}
	while (*str != '\0')
	{
		if (*str < '0' || '9' < *str)
			return (-1);
		else
		{
			if (overflows(current_num, *str) != 0)
				return (-1);
			current_num = current_num * 10 + (*str - '0');
			str += 1;
		}
	}
	return (current_num);
}

static int	overflows(int current, char next)
{
	int	next_num;

	if (next < '0' || '9' < next)
		return (-1);
	next_num = next - '0';
	if (current > INT_MAX / 10)
		return (1);
	else if (current < INT_MAX / 10)
		return (0);
	else
	{
		if (next_num > INT_MAX % 10)
			return (1);
		else
			return (0);
	}
}
