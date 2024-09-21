/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:22:07 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/31 22:48:56 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_node(int argc, char **argv);
static void	free_stack(t_stack *should_be_free);

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		node_num;

	node_num = count_node(argc, &argv[0]);
	stack_a = create_stack(node_num, argc, &argv[0]);
	stack_b = initialize_stack(node_num);
	if (node_num == 1)
		return (0);
	if (node_num == 2 || node_num == 3)
		smallest_nodes_operation(stack_a);
	else if (node_num == 4)
		four_nodes_operation(stack_a, stack_b);
	else if (node_num == 5)
		five_nodes_operation(stack_a, stack_b);
	else
		many_nodes_operation(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
// __attribute((destructor)) static void destructor()
// {
//     system("leaks -q push_swap");
// }

static int	count_node(int argc, char **argv)
{
	int		node_num;
	char	*num_set;

	if (argv == NULL || argv[1] == NULL)
		exit(1);
	node_num = 0;
	num_set = argv[1];
	if (argc <= 1)
		exit(0);
	else if (argc > 2)
		return (argc - 1);
	else
	{
		while (*num_set != '\0')
		{
			while (ft_isspace(*num_set) == 1)
				num_set += 1;
			if (*num_set != '\0')
				node_num += 1;
			while (ft_isspace(*num_set) == 0 && *num_set != '\0')
				num_set += 1;
		}
		return (node_num);
	}
}

static void	free_stack(t_stack *should_be_free)
{
	t_node	*current_position;

	if (should_be_free == NULL)
		return ;
	while (should_be_free->top)
	{
		current_position = should_be_free->top;
		should_be_free->top = should_be_free->top->prev;
		free(current_position);
	}
	free(should_be_free);
}
