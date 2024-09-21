/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_input_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:25:14 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/31 22:21:51 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		create_input_list(int argc, char **argv, int *foundation);
static void	process_single_arg(char *argument, int *foundation);
static void	process_multiple_arg(int argc, char **argv, int *foundation);

void	create_input_list(int argc, char **argv, int *foundation)
{
	if (argv == NULL || argv[1] == NULL || foundation == NULL)
		exit(1);
	if (argc <= 1)
		exit(0);
	if (argc == 2)
		process_single_arg(argv[1], foundation);
	else
		process_multiple_arg(argc, argv, foundation);
}

static void	process_single_arg(char *argument, int *foundation)
{
	int	index;

	if (argument == NULL || foundation == NULL)
		exit(1);
	index = 0;
	while (*argument != '\0')
	{
		while (ft_isspace(*argument) == 1)
			argument += 1;
		if (*argument != '\0')
		{
			foundation[index] = atoi_or_exit(argument);
			index += 1;
		}
		while (ft_isspace(*argument) == 0 && *argument != '\0')
			argument += 1;
	}
}

static void	process_multiple_arg(int argc, char **argv, int *foundation)
{
	int		index;

	if (argv == NULL || foundation == NULL)
		exit(1);
	index = 0;
	while (index + 1 < argc)
	{
		if (argv[index + 1] == NULL)
			exit(1);
		foundation[index] = atoi_or_exit(argv[index + 1]);
		index += 1;
	}
}
