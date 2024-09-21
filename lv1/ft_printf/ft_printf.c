/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:01:33 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/14 15:23:18 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	skip_brank(char **str);
static int	print_variable(char var_type, va_list args);

int	ft_printf(const char *main_str, ...)
{
	va_list		args;
	int			print_count;
	char		*main_str_local;

	va_start(args, main_str);
	print_count = 0;
	main_str_local = (char *)main_str;
	while (*main_str_local != '\0')
	{
		if (*main_str_local == '%')
		{
			main_str_local += 1;
			skip_brank(&main_str_local);
			print_count += print_variable(*main_str_local, args);
		}
		else
		{
			write(1, main_str_local, 1);
			print_count += 1;
		}
		main_str_local += 1;
	}
	va_end(args);
	return (print_count);
}

static void	skip_brank(char **str)
{
	while (**str == ' ')
		*str += 1;
}

static int	print_variable(char var_type, va_list args)
{
	if (var_type == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else if (var_type == 'c' || var_type == 's')
		return (print_string_variable(var_type, args));
	else if (var_type == 'i' || var_type == 'd')
		return (print_integer_variable(args));
	else if (var_type == 'x' || var_type == 'X')
		return (print_hexadecimal_variable(var_type, args));
	else if (var_type == 'u')
		return (print_unsigned_variable(args));
	else if (var_type == 'p')
		return (print_pointer_variable(args));
	else
	{
		write(1, &var_type, 1);
		return (1);
	}
}
