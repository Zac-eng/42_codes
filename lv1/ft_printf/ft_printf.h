/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:25:13 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/17 13:46:16 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int	ft_printf(const char *main_str, ...);
int	print_string_variable(char var_type, va_list args);
int	print_integer_variable(va_list args);
int	print_hexadecimal_variable(char var_type, va_list args);
int	print_unsigned_variable(va_list args);
int	print_pointer_variable(va_list args);
int	put_str_return_len(char *string);
int	put_nbr_return_len(int num);
int	put_hex_return_len(char var_type, unsigned int num);
int	put_uint_return_len(unsigned int num);
int	put_ptr_return_len(uintptr_t ptr);

#endif
