/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:44:12 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/17 22:44:43 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	copy_list(int list_size, int *destination, int *template);
static void	sort_list(int list_size, int *to_be_sorted);
static void	rank_list(int list_size, int *destination, int *sorted_list);

void	compress_list(int list_size, int *to_be_compressed)
{
	int	*sorted_list;

	sorted_list = (int *)malloc(sizeof(int) * list_size);
	if (sorted_list == NULL)
		exit(1);
	copy_list(list_size, sorted_list, to_be_compressed);
	sort_list(list_size, sorted_list);
	rank_list(list_size, to_be_compressed, sorted_list);
	free(sorted_list);
}

static void	copy_list(int list_size, int *destination, int *template)
{
	int	iterator;

	iterator = 0;
	while (iterator < list_size)
	{
		destination[iterator] = template[iterator];
		iterator += 1;
	}
}

static void	sort_list(int list_size, int *to_be_sorted)
{
	int	iterator;
	int	index;
	int	tmp;

	iterator = 0;
	index = 0;
	while (iterator < list_size)
	{
		while (index < list_size - 1)
		{
			if (to_be_sorted[index] > to_be_sorted[index + 1])
			{
				tmp = to_be_sorted[index];
				to_be_sorted[index] = to_be_sorted[index + 1];
				to_be_sorted[index + 1] = tmp;
			}
			else if (to_be_sorted[index] == to_be_sorted[index + 1])
				error_and_exit();
			index += 1;
		}
		iterator += 1;
		index = 0;
	}
}

static void	rank_list(int list_size, int *destination, int *sorted_list)
{
	int	iterator;
	int	index;

	iterator = 0;
	index = 0;
	while (iterator < list_size)
	{
		while (index < list_size)
		{
			if (destination[iterator] == sorted_list[index])
			{
				destination[iterator] = index;
				break ;
			}
			index += 1;
		}
		iterator += 1;
		index = 0;
	}
}
