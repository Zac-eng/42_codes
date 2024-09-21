/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:18:50 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/31 22:39:00 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack		*initialize_stack(int node_num);
static int	is_sorted(int node_num, int *input_list);

t_stack	*create_stack(int node_num, int argc, char **argv)
{
	t_stack	*stack;
	int		*node_list;
	int		iterator;

	if (argv == NULL)
		exit(1);
	iterator = 0;
	node_list = (int *)malloc(sizeof(int) * node_num);
	if (node_list == NULL)
		exit(1);
	stack = initialize_stack(node_num);
	create_input_list(argc, argv, node_list);
	compress_list(node_num, node_list);
	if (is_sorted(node_num, node_list) == 1)
		exit(0);
	while (iterator < node_num)
	{
		push_top(stack, node_list[iterator]);
		rotate(stack);
		iterator += 1;
	}
	free(node_list);
	return (stack);
}

t_stack	*initialize_stack(int node_num)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (new_stack == NULL)
		exit(1);
	new_stack->current_size = 0;
	new_stack->max_size = node_num;
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	return (new_stack);
}

static int	is_sorted(int node_num, int *input_list)
{
	int	index;

	if (input_list == NULL)
		exit(1);
	index = 0;
	while (index < node_num - 1)
	{
		if (input_list[index] > input_list[index + 1])
			return (0);
		else
			index += 1;
	}
	return (1);
}
