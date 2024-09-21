/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:04:04 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/30 19:48:39 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int		check_overflow(double return_num, char input);
static double	create_int_part(char *input);
static double	create_decimal_part(char *input);

double	ft_atof(char *input)
{
	int		sign;
	double	return_num;
	double	decimal_part;

	if (input == NULL)
		show_input_choice();
	sign = 1;
	if (*input == '-')
	{
		sign = -1;
		input += 1;
	}
	return_num = create_int_part(input);
	while (*input != '\0' && *input != '.')
		input += 1;
	if (*input == '.')
		input += 1;
	decimal_part = create_decimal_part(input);
	if (return_num == DBL_MAX && decimal_part > 0)
		show_input_choice();
	return_num += decimal_part;
	return_num *= sign;
	return (return_num);
}

static double	create_int_part(char *input)
{
	double	return_num;

	if (input == NULL || *input == '\0')
		show_input_choice();
	if (*input == '0')
	{
		input += 1;
		if (*input == '\0' || *input == '.')
			return (0);
		else
			show_input_choice();
	}
	while (*input != '\0' && *input != '.')
	{
		if (*input < '0' || '9' < *input)
			show_input_choice();
		if (check_overflow(return_num, *input) == 1)
			show_input_choice();
		return_num = return_num * 10.0 + (*input - '0');
		input += 1;
	}
	return (return_num);
}

static double	create_decimal_part(char *input)
{
	double	return_num;
	double	digit;
	double	next_dbl;

	if (input == NULL)
		show_input_choice();
	else if (*input == '\0')
		return (0);
	return_num = 0;
	digit = 1;
	while (*input != '\0')
	{
		if (*input < '0' || '9' < *input)
			show_input_choice();
		next_dbl = (*input - '0') * pow(0.1, digit);
		return_num += next_dbl;
		input += 1;
		digit += 1;
	}
	return (return_num);
}

static int	check_overflow(double return_num, char input)
{
	double	next_num;

	next_num = (double)(input - '0');
	if (return_num > (DBL_MAX - next_num) / 10)
		return (1);
	return (0);
}
