/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:33:11 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/17 13:55:20 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recursive_print_capital(unsigned int num, int *print_count);
static void	recursive_print_lower(unsigned int num, int *print_count);
static void	put_hex_capital(int num);
static void	put_hex_lower(int num);

int	put_hex_return_len(char var_type, unsigned int num)
{
	int				print_count;	

	print_count = 0;
	if (var_type == 'X')
		recursive_print_capital(num, &print_count);
	else
		recursive_print_lower(num, &print_count);
	return (print_count);
}

static void	recursive_print_capital(unsigned int num, int *print_count)
{
	if (num >= 16)
		recursive_print_capital(num / 16, print_count);
	put_hex_capital(num % 16);
	*print_count += 1;
}

static void	recursive_print_lower(unsigned int num, int *print_count)
{
	if (num >= 16)
		recursive_print_lower(num / 16, print_count);
	put_hex_lower(num % 16);
	*print_count += 1;
}

static void	put_hex_capital(int num)
{
	char	for_put;

	if (0 <= num && num <= 9)
	{
		for_put = num + '0';
		write(1, &for_put, 1);
	}
	else
	{
		for_put = num - 10 + 'A';
		write(1, &for_put, 1);
	}
}

static void	put_hex_lower(int num)
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
