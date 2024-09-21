/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:24:18 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/24 13:54:12 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string_variable(char var_type, va_list args)
{
	char	*arg_str;
	char	arg_chr;

	if (var_type == 'c')
	{
		arg_chr = va_arg(args, int);
		write(1, &arg_chr, 1);
		return (1);
	}
	if (var_type == 's')
	{
		arg_str = va_arg(args, char *);
		return (put_str_return_len(arg_str));
	}
	else
		return (0);
}

int	print_integer_variable(va_list args)
{
	int	argument;

	argument = va_arg(args, int);
	return (put_nbr_return_len(argument));
}

int	print_hexadecimal_variable(char var_type, va_list args)
{
	int	argument;

	argument = va_arg(args, int);
	return (put_hex_return_len(var_type, argument));
}

int	print_unsigned_variable(va_list args)
{
	unsigned int	argument;

	argument = va_arg(args, unsigned int);
	return (put_uint_return_len(argument));
}

int	print_pointer_variable(va_list args)
{
	uintptr_t	argument;
	int			put_count;

	put_count = 0;
	argument = va_arg(args, uintptr_t);
	write(1, "0x", 2);
	put_count += 2;
	put_count += put_ptr_return_len(argument);
	return (put_count);
}
