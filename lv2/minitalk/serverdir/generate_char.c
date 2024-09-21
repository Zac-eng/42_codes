/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:16:33 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/15 13:08:11 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	generate_char(int *bin_array)
{
	int		digit;
	char	print_char;

	digit = 0;
	print_char = 0;
	while (digit < 8)
	{
		print_char = print_char * 2 + bin_array[digit];
		digit += 1;
	}
	ft_printf("%c", print_char);
}
