/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:45:23 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/14 17:47:38 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recursive_print_ptr(uintptr_t ptr, int *print_count);
static void	put_ptr_lower(int num);

int	put_ptr_return_len(uintptr_t ptr)
{
	int		print_count;	

	print_count = 0;
	recursive_print_ptr(ptr, &print_count);
	return (print_count);
}

static void	recursive_print_ptr(uintptr_t ptr, int *print_count)
{
	if (ptr >= 16)
		recursive_print_ptr(ptr / 16, print_count);
	put_ptr_lower(ptr % 16);
	*print_count += 1;
}

static void	put_ptr_lower(int num)
{
	char	for_put;

	if (0 <= num && num <= 9)
	{
		for_put = num + '0';
		write(1, &for_put, 1);
	}
	else
	{
		for_put = num - 10 + 'a';
		write(1, &for_put, 1);
	}
}
