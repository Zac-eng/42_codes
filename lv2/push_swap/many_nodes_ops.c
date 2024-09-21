/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_nodes_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:58:44 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/31 21:52:20 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	power(int radix, int of);
static int	get_num_ofdigit(int bin_digit, int node_body);

void	many_nodes_operation(t_stack *stack_a, t_stack *stack_b)
{
	int		bin_digit;
	int		iter;

	bin_digit = 0;
	iter = 0;
	while (power(2, bin_digit) <= stack_a->max_size)
	{
		while (iter < stack_a->max_size)
		{
			if (get_num_ofdigit(bin_digit, stack_a->top->body) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			iter += 1;
		}
		while (stack_b->current_size > 0)
			pa(stack_a, stack_b);
		iter = 0;
		bin_digit += 1;
	}
}

static int	power(int radix, int of)
{
	if (of == 0)
		return (1);
	return (radix * power(radix, of - 1));
}

static int	get_num_ofdigit(int bin_digit, int node_body)
{
	return ((node_body % power(2, bin_digit + 1)) / power(2, bin_digit));
}
