/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:39:02 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/14 17:54:37 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_ulong(long long int num_long, int *put_count);

int	put_str_return_len(char *string)
{
	int	print_count;

	print_count = 0;
	if (string == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*string != '\0')
	{
		write(1, string, 1);
		string += 1;
		print_count += 1;
	}
	return (print_count);
}

int	put_nbr_return_len(int num)
{
	int				put_count;
	long long int	num_long;

	put_count = 0;
	num_long = num;
	if (num_long < 0)
	{
		write(1, "-", 1);
		put_count += 1;
		num_long *= -1;
	}
	put_ulong(num_long, &put_count);
	return (put_count);
}

int	put_uint_return_len(unsigned int num)
{
	int	put_count;

	put_count = 0;
	put_ulong(num, &put_count);
	return (put_count);
}

static void	put_ulong(long long int num_long, int *put_count)
{
	char	for_putnum;

	for_putnum = num_long % 10 + '0';
	if (num_long >= 10)
		put_ulong(num_long / 10, put_count);
	write(1, &for_putnum, 1);
	*put_count += 1;
}
