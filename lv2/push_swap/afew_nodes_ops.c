/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afew_nodes_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:14:29 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/23 23:03:11 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallest_nodes_operation(t_stack *stack)
{
	if (stack == NULL)
		exit(1);
	if (stack->top->body > stack->top->prev->body && \
	stack->top->body > stack->bottom->body)
		ra(stack);
	if (stack->top->body < stack->top->prev->body && \
	stack->top->body < stack->bottom->body)
	{
		if (stack->top->prev->body < stack->bottom->body)
			return ;
		else
		{
			sa(stack);
			ra(stack);
			return ;
		}
	}
	if (stack->top->prev->body < stack->bottom->body)
		return (sa(stack));
	else
		return (rra(stack));
}

void	four_nodes_operation(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	while (stack_a->top->body != 0)
		ra(stack_a);
	pb(stack_a, stack_b);
	smallest_nodes_operation(stack_a);
	pa(stack_a, stack_b);
	return ;
}

void	five_nodes_operation(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	while (stack_a->top->body != 0 && stack_a->top->body != 1)
		ra(stack_a);
	pb(stack_a, stack_b);
	while (stack_a->top->body != 0 && stack_a->top->body != 1)
		ra(stack_a);
	pb(stack_a, stack_b);
	smallest_nodes_operation(stack_a);
	if (stack_b->top->body == 0)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	return ;
}
