/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:30:21 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/31 20:10:23 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_which_set(int argc, char *argv);

int	main(int argc, char *argv[])
{
	int		which_set;
	double	parameter[2];

	which_set = check_which_set(argc, argv[1]);
	if (which_set == 1)
	{
		if (argc != 4)
			show_input_choice();
		parameter[0] = ft_atof(argv[2]);
		parameter[1] = ft_atof(argv[3]);
		if (hypot(parameter[0], parameter[1]) > 2)
			show_input_choice();
		julia_operation(&parameter[0]);
	}
	else if (which_set == 2)
	{
		if (argc != 2)
			show_input_choice();
		mandelbrot_operation();
	}
	return (0);
}

static int	check_which_set(int argc, char *argv)
{
	if (argc <= 1 || argv == NULL)
		show_input_choice();
	if (ft_strcmp(argv, "julia") != 1 && ft_strcmp(argv, "mandelbrot") != 1)
		show_input_choice();
	if (ft_strcmp(argv, "julia") == 1)
	{
		if (argc != 4)
			show_input_choice();
		return (1);
	}
	if (ft_strcmp(argv, "mandelbrot") == 1)
	{
		if (argc != 2)
			show_input_choice();
		return (2);
	}
	show_input_choice();
	return (0);
}

void	show_input_choice(void)
{
	ft_printf("command-line arguments should follow \
either of the formats below\n");
	ft_printf("1: mandelbrot\n");
	ft_printf("2: julia <real part> <imaginary part>\n");
	ft_printf("\n");
	ft_printf("Attention:\n");
	ft_printf("julia set parameter should be less than 2 in hypotenuse and expressed by \
using only number characters\n");
	exit(0);
}
